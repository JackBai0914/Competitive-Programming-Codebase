

## Motion.py

- update_positions: 人群移动一个时间单位

- out_of_bounds: 处理人群出界情况（reassign速度）

- update_randoms: 给人群赋予随机方向和速度
- get_motion_parameters: 输出人群移动以后所在的矩形的参数



## Population.py <- motion

- 每个人用15维的向量表示：

  ```shell
      0 : unique ID
      1 : current x coordinate
      2 : current y coordinate
      3 : current heading in x direction
      4 : current heading in y direction
      5 : current speed
      6 : current state (0=healthy, 1=sick, 2=immune, 3=dead, 4=immune but infectious)
      7 : age
      8 : infected_since (frame the person got infected)
      9 : recovery vector (used in determining when someone recovers or dies)
      10 : in treatment
      11 : active destination (0 = random wander, 1, .. = destination matrix index)
      12 : at destination: whether arrived at destination (0=traveling, 1=arrived)
      13 : wander_range_x : wander ranges on x axis for those who are confined to a location
      14 : wander_range_y : wander ranges on y axis for those who are confined to a location
  ```

  

- initialize_population:

  初始化所有人口信息；包括所有人的随机年龄，随机坐标，随机速度，

- set_destination_bounds

  将一部分人群移动到某一个统一的坐标附近，并设置wander范围

- Population_trackers:

  统计人群中感染，免疫人数的工具

## Path_planning.py <- motion

- go_to_location

  如果有目的地，将某一个病人移动到某一个目的地附近

- set_destination

  如果有目的地 (destination marker is not 0)，将所有人（根据目的地）确定速度和方向。

- check_at_destination

  找出已经到达目的地的人，标记已到达目的地，并赋予他们随机速度。

- keep_at_destination

  对于标记已到达目的地的人，确保他们的移动在wander区间内。

- reset_destinations

  清空所有人的到达标记。

## Infection.py <- path planning

- find_nearby

  计算某个区域内健康人群的indices or 感染人群的人数

- infect

  计算新感染。

- recover_or_die

  计算感染人群的死去/恢复。

- compute_mortality

  给定年龄，计算感染率
  
- healthcare_infection_correction
  

计算医务人员的感染对医疗资源的影响情况；未实现。

## environment.py

- build_hospital

  画出医院

  ## Visualizer.py <- environment.py

- draw_tstep

  画一帧的人口分布图

- plot_sir

  画SIR曲线

## Simulation

- Simulation class: 

  - tstep: 模拟一个时间周期内发生的所有事：

    定目标，移动，新感染，新康复/死亡，进/出医院，可视化。

  - run: 模拟所有时间周期内发生的所有事。

- 这个程序可以直接运行，出来就是最基础的随机游走



# 可做的修改

## 非常简单的修改

### 改变人群活动范围，感染半径，最大活动速度

直接改变initialize_population，update_randoms，infect，compute_mortality函数的初始参数。

### 增加social lockdown

在感染人数达到一定比例以后，将90%的点的速度改成0就好。

## 给人群增加目的地

这个程序写好了很多“目的地”的工具函数，但是在simulation里一个目的地都没有设置...(在simulation里，每一个人的第11维永远为0，所以simulation里根本没有展示怎么设定目标)。如果要给人群设定固定的目标（比如，让每个人每隔10个时间节点就必须去一次“超市”再回家），需要改两个大方面。

第一方面是要改destination数组。目前它被initialize_destination_matrix设为全零，我们要给它赋值，格式为[第一个目标的x坐标，第一个目标的y坐标，第二个目标的x...]

第二方面是在set_destination_bounds改每个人的第11维。

在simulation中，作者好像已经写好了处理所有目的地的代码。所以如果我们正确的初始化所有人的目的地，应该就好。



## 给人群运动的边界设定成特定形状

只需要修改update_randoms和out_of_bounds函数。全局存储一个01矩阵，代表伦敦城市的形状；如果某一个人在某一次随机速度和方向以后，下一个时间点将要落在0的位置（这代表走出了我们规定的地图），我们就给他重新随机一遍速度和方向，知道下一次走到地图内为止。这样做比较简单，但是忽略了人口密度。

也需要修改initialize_population当中所有人坐标的初始化（同样的改法）。

## 建立医院

原作者代码里只有医院的可视化。换句话说，医院就是一个区域，每个人在得病以后都会将目的地设成那个区域。这种实现的局限性非常大（感染者在前往医院的过程中会感染很多人，医院区域周围会有很多人感染，就像做着最后一个展示的视频一样）；在实现了“加目的地”的功能以后，在infect函数里加上目的地，就可以实现建立医院。

## 疫苗

### 随机打疫苗

非常好实现，在每一个时间节点，随机将一部分人的第6个维度改成2(recovered)就好。

### 按照区域打疫苗

疫苗也可以看作是一个“感染源”，会“传染”一定区域内的一部分人。所以，我们需要写一个类似find_nearby的函数，只不过在区间里的人有一定几率直接recover。

