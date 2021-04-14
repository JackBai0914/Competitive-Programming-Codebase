#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstddef>
#include <omp.h>

#ifndef _SYRAH_CYCLE_TIMER_H_
#define _SYRAH_CYCLE_TIMER_H_

#if defined(__APPLE__)
  #if defined(__x86_64__)
    #include <sys/sysctl.h>
  #else
    #include <mach/mach.h>
    #include <mach/mach_time.h>
  #endif // __x86_64__ or not

  #include <stdio.h>  // fprintf
  #include <stdlib.h> // exit

#elif _WIN32
#  include <windows.h>
#  include <time.h>
#else
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <sys/time.h>
#endif


  // This uses the cycle counter of the processor.  Different
  // processors in the system will have different values for this.  If
  // you process moves across processors, then the delta time you
  // measure will likely be incorrect.  This is mostly for fine
  // grained measurements where the process is likely to be on the
  // same processor.  For more global things you should use the
  // Time interface.

  // Also note that if you processors' speeds change (i.e. processors
  // scaling) or if you are in a heterogenous environment, you will
  // likely get spurious results.
  class CycleTimer {
  public:
    typedef unsigned long long SysClock;

    //////////
    // Return the current CPU time, in terms of clock ticks.
    // Time zero is at some arbitrary point in the past.
    static SysClock currentTicks() {
#if defined(__APPLE__) && !defined(__x86_64__)
      return mach_absolute_time();
#elif defined(_WIN32)
      LARGE_INTEGER qwTime;
      QueryPerformanceCounter(&qwTime);
      return qwTime.QuadPart;
#elif defined(__x86_64__)
      unsigned int a, d;
      asm volatile("rdtsc" : "=a" (a), "=d" (d));
      return static_cast<unsigned long long>(a) |
        (static_cast<unsigned long long>(d) << 32);
#elif defined(__ARM_NEON__) && 0 // mrc requires superuser.
      unsigned int val;
      asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(val));
      return val;
#else
      timespec spec;
      clock_gettime(CLOCK_THREAD_CPUTIME_ID, &spec);
      return CycleTimer::SysClock(static_cast<float>(spec.tv_sec) * 1e9 + static_cast<float>(spec.tv_nsec));
#endif
    }

    //////////
    // Return the current CPU time, in terms of seconds.
    // This is slower than currentTicks().  Time zero is at
    // some arbitrary point in the past.
    static double currentSeconds() {
      return currentTicks() * secondsPerTick();
    }

    //////////
    // Return the conversion from seconds to ticks.
    static double ticksPerSecond() {
      return 1.0/secondsPerTick();
    }

    static const char* tickUnits() {
#if defined(__APPLE__) && !defined(__x86_64__)
      return "ns";
#elif defined(__WIN32__) || defined(__x86_64__)
      return "cycles";
#else
      return "ns"; // clock_gettime
#endif
    }

    //////////
    // Return the conversion from ticks to seconds.
    static double secondsPerTick() {
      static bool initialized = false;
      static double secondsPerTick_val;
      if (initialized) return secondsPerTick_val;
#if defined(__APPLE__)
  #ifdef __x86_64__
      int args[] = {CTL_HW, HW_CPU_FREQ};
      unsigned int Hz;
      size_t len = sizeof(Hz);
      if (sysctl(args, 2, &Hz, &len, NULL, 0) != 0) {
         fprintf(stderr, "Failed to initialize secondsPerTick_val!\n");
         exit(-1);
      }
      secondsPerTick_val = 1.0 / (double) Hz;
  #else
      mach_timebase_info_data_t time_info;
      mach_timebase_info(&time_info);

      // Scales to nanoseconds without 1e-9f
      secondsPerTick_val = (1e-9*static_cast<double>(time_info.numer))/
        static_cast<double>(time_info.denom);
  #endif // x86_64 or not
#elif defined(_WIN32)
      LARGE_INTEGER qwTicksPerSec;
      QueryPerformanceFrequency(&qwTicksPerSec);
      secondsPerTick_val = 1.0/static_cast<double>(qwTicksPerSec.QuadPart);
#else
      FILE *fp = fopen("/proc/cpuinfo","r");
      char input[1024];
      if (!fp) {
         fprintf(stderr, "CycleTimer::resetScale failed: couldn't find /proc/cpuinfo.");
         exit(-1);
      }
      // In case we don't find it, e.g. on the N900
      secondsPerTick_val = 1e-9;
      while (!feof(fp) && fgets(input, 1024, fp)) {
        // NOTE(boulos): Because reading cpuinfo depends on dynamic
        // frequency scaling it's better to read the @ sign first
        float GHz, MHz;
        if (strstr(input, "model name")) {
          char* at_sign = strstr(input, "@");
          if (at_sign) {
            char* after_at = at_sign + 1;
            char* GHz_str = strstr(after_at, "GHz");
            char* MHz_str = strstr(after_at, "MHz");
            if (GHz_str) {
              *GHz_str = '\0';
              if (1 == sscanf(after_at, "%f", &GHz)) {
                //printf("GHz = %f\n", GHz);
                secondsPerTick_val = 1e-9f / GHz;
                break;
              }
            } else if (MHz_str) {
              *MHz_str = '\0';
              if (1 == sscanf(after_at, "%f", &MHz)) {
                //printf("MHz = %f\n", MHz);
                secondsPerTick_val = 1e-6f / GHz;
                break;
              }
            }
          }
        } else if (1 == sscanf(input, "cpu MHz : %f", &MHz)) {
          //printf("MHz = %f\n", MHz);
          secondsPerTick_val = 1e-6f / MHz;
          break;
        }
      }
      fclose(fp);
#endif

      initialized = true;
      return secondsPerTick_val;
    }

    //////////
    // Return the conversion from ticks to milliseconds.
    static double msPerTick() {
      return secondsPerTick() * 1000.0;
    }

  private:
    CycleTimer();
  };

#endif // #ifndef _SYRAH_CYCLE_TIMER_H_


#ifndef __BFS_H__
#define __BFS_H__

struct graph;

struct solution
{
    int* distances;
};

struct vertex_set {
    int  count;
    int  alloc_count;
    int* present;
};


void bfs_bottom_up(graph* graph, solution* sol);
void bfs_top_down(graph* graph, solution* sol);
void bfs_hybrid(graph* graph, solution* sol);

#endif

// #include "graph.h"

#define ROOT_NODE_ID                    0
#define NOT_VISITED_MARKER              -1
#define BOTTOMUP_NOT_VISITED_MARKER     0
#define PADDING                         16
#define THRESHOLD                       10000000




void vertex_set_clear(vertex_set* list) {
    list->count = 0;
}

void vertex_set_init(vertex_set* list, int count) {
    list->alloc_count = count;
    list->present = (int*)malloc(sizeof(int) * list->alloc_count);
    vertex_set_clear(list);
}







void bottom_up_step(
    graph* g,
    vertex_set* frontier,    
    int* distances,
    int iteration) {
    
    // #pragma omp parallel num_threads(NUM_THREADS) private(local_count) 
    // #pragma omp parallel private(local_count)    
    // #pragma omp parallel num_threads(NUM_THREADS) private(local_count) 
    int local_count = 0;
    int padding[15];
    #pragma omp parallel 
    {
        #pragma omp for reduction(+:local_count)
        for (int i=0; i < g->num_nodes; i++) {                   
            if (frontier->present[i] == BOTTOMUP_NOT_VISITED_MARKER) {
                int start_edge = g->incoming_starts[i];
                int end_edge = (i == g->num_nodes-1)? g->num_edges : g->incoming_starts[i + 1];
                for(int neighbor = start_edge; neighbor < end_edge; neighbor++) {
                    int incoming = g->incoming_edges[neighbor];
                    // if(__sync_bool_compare_and_swap(&frontier->present[incoming], iteration, distances[node] + 1)) {
                    if(frontier->present[incoming] == iteration) {
                        distances[i] = distances[incoming] + 1;                        
                        local_count ++;
                        frontier->present[i] = iteration + 1;
                        break;
                    }
                }
            }
        }
        // #pragma omp atomic
        //     frontier->count += local_count;
    }    
    frontier->count = local_count;

}

void bfs_bottom_up(graph* graph, solution* sol)
{

    vertex_set list1;
    
    vertex_set_init(&list1, graph->num_nodes);
    
    int iteration = 1;

    vertex_set* frontier = &list1; 
    
    memset(frontier->present, 0, sizeof(int) * graph->num_nodes);
            
    // setup frontier with the root node    
    // just like put the root into queue
    frontier->present[frontier->count++] = 1;

    // set the root distance with 0
    // sol->distances[ROOT_NODE_ID] = 0;
    for (int i=0; i<graph->num_nodes; i++)
        sol->distances[i] = 0;

    
    // printf("!!!!!!!!!!!!!!!!!!!!fro2: %-10d\n", frontier->count);
    // just like pop the queue
    while (frontier->count != 0) {
        
        frontier->count = 0;
        // double start_time = CycleTimer::currentSeconds();
        

        bottom_up_step(graph, frontier, sol->distances, iteration);

        // double end_time = CycleTimer::currentSeconds();
        // printf("frontier=%-10d %.4f sec\n", frontier->count, end_time - start_time);

        iteration++;

    }

    
}



// void bottom_up_step(
void top_down_step(
    graph* g,
    vertex_set* frontier,    
    int* distances,    
    int iteration)
{
    
    int local_count = 0; 
    int padding[15];  
    #pragma omp parallel 
    {
        #pragma omp for reduction(+ : local_count)
        for (int i=0; i < g->num_nodes; i++) {   
            if (frontier->present[i] == iteration) {             
                int start_edge = g->outgoing_starts[i];
                int end_edge = (i == g->num_nodes-1) ? g->num_edges : g->outgoing_starts[i+1];
                // attempt to add all neighbors to the new frontier            
                for (int neighbor=start_edge; neighbor<end_edge; neighbor++) {
                    int outgoing = g->outgoing_edges[neighbor];
                    if(frontier->present[outgoing] == BOTTOMUP_NOT_VISITED_MARKER) {  
                    // if(__sync_bool_compare_and_swap(&frontier->present[outgoing], BOTTOMUP_NOT_VISITED_MARKER, iteration + 1)) {                  
                        distances[outgoing] = distances[i] + 1;
                        local_count ++;
                        frontier->present[outgoing] = iteration + 1;
                    }
                }
            }
        }
        
        // #pragma omp atomic                    
        //     frontier->count += local_count;
    }
    frontier->count = local_count;
}








// Implements top-down BFS.
//
// Result of execution is that, for each node in the graph, the
// distance to the root is stored in sol.distances.
// void bfs_bottom_up(graph* graph, solution* sol) {
void bfs_top_down(graph* graph, solution* sol) {
    

    vertex_set list1;
    
    vertex_set_init(&list1, graph->num_nodes);    

    int iteration = 1;

    vertex_set* frontier = &list1;
            
    memset(frontier->present, 0, sizeof(int) * graph->num_nodes);

    frontier->present[frontier->count++] = 1;        

    // set the root distance with 0
    sol->distances[ROOT_NODE_ID] = 0;    
        
    
    // just like pop the queue
    while (frontier->count != 0) {

        frontier->count = 0;

        // double start_time = CycleTimer::currentSeconds();


        top_down_step(graph, frontier, sol->distances, iteration);
        // bottom_up_step(graph, frontier1, sol->distances, iteration);

        // double end_time = CycleTimer::currentSeconds();
        // printf("frontier=%-10d %.4f sec\n", frontier->count, end_time - start_time);

        iteration++;
    }    

}






void bfs_hybrid(graph* graph, solution* sol) {

    vertex_set list1;
    
    vertex_set_init(&list1, graph->num_nodes);
    
    int iteration = 1;

    vertex_set* frontier = &list1;    
        
    // setup frontier with the root node    
    // just like put the root into queue
    memset(frontier->present, 0, sizeof(int) * graph->num_nodes);

    frontier->present[frontier->count++] = 1;

    // set the root distance with 0
    sol->distances[ROOT_NODE_ID] = 0;
    
    // just like pop the queue
    while (frontier->count != 0) {
        
        
        // double start_time = CycleTimer::currentSeconds();
        
        if(frontier->count >= THRESHOLD) {
            frontier->count = 0;
            bottom_up_step(graph, frontier, sol->distances, iteration);
        }
        else {
            frontier->count = 0;
            top_down_step(graph, frontier, sol->distances, iteration);
        }

        // double end_time = CycleTimer::currentSeconds();
        // printf("frontier=%-10d %.4f sec\n", frontier->count, end_time - start_time);

        iteration++;


    }     
}