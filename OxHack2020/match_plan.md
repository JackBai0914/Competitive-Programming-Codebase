



## 结构体

### Hangout

- User Host

- User Requirement

- User Participant 

- Location, Activity Type, Time

- status (e.g. available, interested, upcoming, successful)

  

Methods:

be_Interested(Hangout h, User P)

h.participant = p;

h.status = interested;





accept(Hangout h)

h.status = upcoming



reject(Hangout h)

h.status = available;

- notify the participant

h.participant = null;

- Refresh home page



delete(Hangout h)

- H retrieve from the database



Show_hangouts(User u)

- Display all hangouts whose requirements User u meets. 

### TimeTable (global variable)

- [[Time 1 <Events at time 1>],[Time 2 <Events at time 2>],...]

### User

- String <Bio> (Name,  College, Department, Year, Email (@college/department.ox.ac.uk), Phone number, Gender, Pronouns Hobbies/Interests, Profile Picture)

- 时间preference

- Schedule (Availability) e.g: available at 9am, 10am,...,19am, not available at 20am,...

- List of assignments

- List of events

  

#### Global Users_stat

#### Global Assignments



## Functions

1. void update_event (Event e)

   Function: 

   - Add e to each of the 2 users timetable and the total timetable.

     

2. Void choose_user2 (Assignment a, [users] users_list)

   Function: 

   - Randomly choose one user from a list of users that fits the model, add it to e.

   - Remove a from the list Assignments.

     

3. Bool fit(User u, User model)

   Function:

   - Return True if the user fits the model, False o/w

   

4. Events (int time)

   Function:

   - Return the list of events happening at a specific time 

     

