#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)
## Joey Netterville joey.netterville@ucf.edu

This is the framework for homework #2. 

The assignment is due: **Tuesday, March 28 at 11:59PM (EST)**

# Part 1) Empirical Test of Randomness
- a) See [01.random number data.statistics 1.xlsx] [PlAA] each tab has a random number engine with associated chart showing the distribution for n=1000. Statistics are listed on the final tab. 
    - a) I generated average, median and stdev for each point. Statistics isn't something i do on a regular basis. In a team, I would look to others for additional statistics. 
    - b) I started researching how to generated the other suggested stats and realized i was out of depth and moved on to other parts. 
- b) I ran varied n sizes from my initial distribution. Statistics were generated and listed on the stats page. 
    - a) As N gets smaller, the STdev increases. Since I used smaller samples within the main set it changed the overall distribution of numbers within each set. 
- c) See [02.distribution data statistics.xlsx] [BBBB]. Each tab is a distribution and numbers are represented by a side by side chart. statistics are listed on the stats tab. 
    - a) I reduced n to 1000 for this run. 
    - b) uniform and normal distribution made sense. I'm not sure what was entirely going on with the other distributions.
- d) See [03.random number unit square.xlsx] [CCCC] n=1000 for these. I generated 2 sets of data and used one for X and the other for y. I used uniform distribution and set bounds of -1 , 1
    - a) mr19937_64 has an n-10,000 
    - b) I think the first point to mention is n=1k isn't high enough. At the same time, 100,000 was too much. 50,000 also seemed to be too much. 
    - c) you need a meaningful sample size. As we were repeating a lot of tests here i settled on 1k for clarity with a second higher example. 
    - d) for the random numbers, they appear to be randomly distributed within the unit square
    - e) i didn't see any discernable patterns. It might be meaningful to repeat the test 5000 times and compare those results against each other.
    - f) as for part 4, i also generated the results on the unit square within this document. 
    - g) since this is generated in Excel, I did a conversion to make it appear no a scatter plot.
    - h) We ran into issues with some of them where they were coming up wrong. I ran an absolute value within the formula before the square root.
    - i) credit to stack overflow for the formula
    - j) this part was tedious af because you change the program, compile, run, output data, move to excel, insert charts. There's probably a better way, but it was outside the scope
- e) See [04.distribution unit.xlsx] [DDDD] n=1000
    - a) a lot of the same caveats as above
    - B) i ran a 10k run on normal as it came out looking good. 
    - c) my image isn't a true square so the circle looks skewed. 
    - d) I displayed results for the others as they came out. I trimmed them to show the results, but they're not bounded by -1,1
    - e) I probably did something wrong here, or it's my lack of understanding. 
    - f) circles are also displayed, but might not be actual circles
    - g) I like the (circle) plot for fischer. it reminds me of a particle emitter, like a damaged space engine from a game. 
- f) See D for random numbers and E for distribution

- g) Initially I didn't include Sobol. I added it as it's own file. See [05.sobol.xlsx] [EEEE].
    - a) I ran this at n-100,000 in the hopes it would look really pattern. 
    - b) We ran multiple tests against this to get it to look more like a pattern but however i changed the parameters it didn't look like the example. 
    - c) It does generate a pattern. But it doesn't look like the example. 
    - d) As of the study group monday, only sarah had a sobol which looked like a pattern.
    - e) her program looked like ours, we weren't sure why she had those results. 
    - f) the takeaway for sobol for me was you could use the seed to get repeatable random numbers

# Part 2) Snakes and Ladders
- a) null state
    - a) initially i generated this in perl as a csv
    - b) in the study group i junked it at the advice of others and we rewrote it as a loop
    - c) I generated the final lines by hand. 
    - d) since we have a matrix initially populated with 0s you only need to mark the areas where you have a result
    - e) the final cell is 1. if you "win" you transition to the same spot all the time.
    - f) the prior line is 1 as well if you're one spot out, all rolls win.
    - g) a good add here would be to terminate the loop when you succeed and mark the roll number
    - h) with the completed code, to run a null state game comment out the transition matrix modification class.
- b) null state analysis: unsure what to do here. 
    - a) Honestly, i'm excited i got the code into a working state where i could see the board. 
    - b) this is a giant leap forward compared to my experience with the jello cube. 
    - c) I think the goal at this point was to look at how many turns it took to get through the board based on how many rolls you have
    - d) I think there's a way to export a game state table which would show the percentage chance to land on each square as well as how often you end the game on specific squares. this would be applicable to both null and transition
    - d) It's possible to win the null state in a range of 17 - 100 games. 44 was about where I saw it start to reasonably converg for me. It was around 50% in the mid 30s. 
	
- c) Snakes and ladders transition
    - a) first item here, when you have a snake or a ladder you have a 0 at the transition point, and the probability is shifted to the destination
    - b) initially i wrote this identifying the column with a result and then subtracting it from the original location and adding it to the new location
    - c) this is important because we have a couple spots where we have overlap. overlap spots represent chance to land on the spot, or chance to be transferred to it
    - d) I ran sanity checking in my routine to sum all rows to verify we hit 1. Then look for stuff like empty variables or areas outside the row
    - e) When i rewrote to the loop i build these transition points by hand. 
    - f) serious take away here, the first row is 0. 
    - g) i had the program print the matrix and regexed it into excel. from there i was able to troubleshoot and clear up any issues
    - h) it takes significantly less rolls to complete when you add in this transition points.
        - potentially you can also fail to complete a game by continually hitting snakes. 
    - i) It would be interesting to see the results of just snakes, or just ladders
- d) is this a game?
    - a) we've discussed this in class a couple times. 
    - b) Games are social constructs to promote social behaviours. 
    - c) I'd argue this is a game because it supports that. The focus is on shared activity around a common goal.
    - d) strategy wise this isn't a good example. results are purely on luck rather than choice. 
- e) see [null state export.txt] [IIII] and [transition export.txt] [JJJJ] for matrixes

# Part 3)	Queue simulator
- a) I have an implemented and working simulation with files on github
- b) implemented
- c) implemented, formulas taken from webcourses. Ran into an issue here where i didn't () a variable and it broke things. Seemed common, I helped a couple of others who had the same issue.
- d) It generates statistics, but unsure how to analyze them
    - It was suggested by a peer in class about how you could look at the times generated per queue and figure out and follow the route through. 
    - This seemed to be generated really well within Anylogic. 
- e) Implemented in Anylogic. see [Security_mm1.alp] [GGGG]

# Part 4) Extra Features
- a) Additional Distribution
    - a) This isn't a tremendous deal. Before I realized we needed to use Sobol as part of the initial random number cases, I used default_random_engine for all tests. 
- b) Use case for Anylogic
    - a) Software Price compared to physical 
    - b) Free student/learning edition available
    - c) Speed to implement. 
    - d) Tools are prebuilt. 
    - e) Visual view of model promotes understanding
    - f) Modular components can be reused in other code
    - g) Provides a virtual environment to test changes
    - h) Modeling the process ahead of time promotes identification of potential issues and risk
    - i) GUI and pre built tools reduce required skillset and barrier to entry
    - j) Supports Agent based, discrete, system dynamics within one tool
    - k) Offers visualizations, broadening the audience and their understanding of the model

# Part 5) Report / Feedback
- In the event any links fail, all files are located at "https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework2/files/"
- Images for the anylogic simulations are listed in the same folder in case there are issues with importing
- I worked with other students as part of this project. I think I accomplished more per unit of time during the study session monday working with the team than I did during the entire project.
- I'd again like to suggest we do more group oriented work. Either as part of the project in class, or in Piazza online, or in teams. 
- Part three made the most sense for me. The Piazza post laid it outthe requirements as well as the procedure in an intuitive fashion. It was less about coding, and more about understanding what was going on.
- The simulation fed into Anylogic and vice versa. Understanding one made the other easier. 
- Reworking the transition matrix felt rewarding, once i had a direction to go in. Seeing the data output and moving the items from the variable sets made it more understandable. Once i have something to work with, i can usually figure out what's wrong with it. But without feedback from the program, I generally feel lost and frustrated. 
- I wasn't in class when we voted on the final. With how much material we've covered in class I'm unsure how to respond. Will the final be math based, programming based, ide based, simulation based, concept based?
- Final note. Thanks!

# Part 6) Extra Credit
- I think of this less as extra credit, and more fill in points for items which didnt get completed
- a) Anylogic snakes and ladders See [SNL1.alp] [FFFF]. 
    - a) I created a partial implementation of of the null state snakes and ladders using Anylogic. 
    - b) It shows a minimum of two rolls and a maximum of 7. 
    - c) Each space on the board is represented by a 0 second queue feeding into a choice object to simulate a roll. 
    - d) Our shortest path through the map is any combination of rolls totaling over 6 ex:1-6,3-4,6-6
    - e) Our longest path through the map would be a roll string of 1,1,1,1,1,1,1
    - f) There were two interesting problems to solve. 1) how to handle the roll within Anylogic and, 2) how to keep everything organized. 
    - g) Anylogic offers two choice trees: A single a/b option, and an a/b/c/d/e option. 
        - 1) Since our dice has 6 sides, we need to implement a workaround. 
        - 2) I fed from the queue into a choice tree with 2 50% option. Each option goes into another choice tree with 3 33% chances to proceed. 
        - 3) this way we have Ex from the starting point a)2,3,4 and b)5,6,7
    - h) Organization also became a key element. 
        - 1) Since each spot on the board creates 3 objects and 8 connection points, it quickly became a spaghetti nightmare. 
        - 2) There might be a more intuitive method within the program which controls where queues feed out to/in from. 
        - 3) In a full implementation, it would be optimal to add bends and connection points between objects, and lay them out cleanly. 
        - 4) Additionally, more space would help distinguish all the items. 
        - 5) With 101 queues, 300 choice objects and connectors between all items it might be difficult to keep track of where everything goes. 
        - 6) Unfortunately this creates a situation where you can't see it all in the same screen.
        - 7) Possibly implementing a 2/3d visualization would simplify keeping track of everything. 
    - i) While unimplemented, snakes and ladders could be implemented by connecting backwards or forwards to other tile objects. 


- b) 2d visualization of Part 3 See [airport with 2d1.alp] [HHHH]
    - Corey showed the study group how to do it and it was pretty easy to duplicate. if anyone deserves extra points for this, it's him for being responsible for explaining it to the rest of us

   [PlAA]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/01.random%20number%20data.statistics1.xlsx>
   [BBBB]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/02.distribution%20data%20statistics.xlsx>
   [CCCC]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/03.random%20number%20unit%20square.xlsx>
   [DDDD]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/04.distribution%20unit.xlsx>
   [EEEE]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/05.sobol.xlsx>
   [FFFF]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/SNL1.alp>
   [GGGG]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/Security_mm1.alp>
   [HHHH]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/airport%20with%202d1.alp>
   [IIII]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/null%20state%20export.txt>
   [JJJJ]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/blob/master/Homework2/files/transition%20export.txt>


