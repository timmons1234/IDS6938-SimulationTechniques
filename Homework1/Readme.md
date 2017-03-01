#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


This is homework #1 by William Netterville. 
[Homework writeup](HomeWork%231.pdf).

The assignment is due: Wednesday, March 01 at 11:59PM (EST)

## Part 1 Files
| Name | File |
| ---- | ---- |
| Data Export   | [files/Numeric.Analysis.xlsx] [File-a] |
| Method Graph  | [files/method.comparison.png] [File-b] |
| Error Graph   | [files/error.comparison.png]  [File-c] |
| 3 point RK4   | [files/rk4.comparison.png]    [File-d] |
| 3 point Error | [files/rk4.error.value.png]   [File-e] |

   [File-a]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/Numeric.Analysis.xlsx>
   [File-b]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/method.comparison.png>
   [File-c]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/error.comparison.png>
   [File-d]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/rk4.comparison.png>
   [File-e]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/rk4.error.value.png>

## Part 1 - A

Integral: e^(x/2) * sin 5x

## Part 1 - B
Df function
```sh
double df(double x, double y)            //function for defining dy/dx
{
	 return y - .5* pow(M_E, (.5 * x))*sin(5 * x) + 5 * pow(M_E, (.5 * x))*cos(5 * x);
}
```
Exact function
```sh
double exact(double x)            //function for defining dy/dx
{
	return pow(M_E, (.5* x)) *sin(5 * x);
}
```
   
## Part 1 - C
| Item | File           |
| ---- | ----           |
| Data Output | [files/integration.md]   [File-f] |
   [File-f]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/integration.md>

## Part 1-D
| Graph | File |
| ----- | ---- |
| Error Graph   | [files/error.comparison.png]  [File-c] |

## Part 1-E
| Graph | File |
| ----- | ---- |
| 3 point RK4   | [files/rk4.comparison.png]    [File-d] |
| 3 point Error | [files/rk4.error.value.png]   [File-e] |

Note here. I read the requirements as use three points here, specifically because we were looking at how having a large stepsize would affect the error rate. Others in class used examples of varying the stepsize in multiple examples. 

## Part 1-F
 - 1) As we move from RK1 to RK4 we increase the sampling of the values along the curve. The more samples we take, the more accurate the final answer
 - 2) As we increase the X value we diverge from the exact value. While RK4 maintains better accuracy due to greater sampling, given a high enough X it will begin to diverge
 - 3) The larger the step size, the faster we see divergence. 3 points vs 100 points allows RK4 to show high levels of divergence 
 - 4) RK4 is the better method because it takes greater sampling into account, but only when we maintain a small step size. 
 
 ## Part 2 Programming the cube
 - 1) Euler, Midpoint are implemented. Initially Midpoint had an error which made the cube fly sideways but has been resolved. 
 - 2) Forces was computed using the assistance in Piazza, then an implemented force equation. I think it's right?
 - 3a) Floor collision is implemented. Ran into an issue where it wasn't loading the floor which was resolved through an absolute file path.
 - 3b) Cylinder Collision is not implemented. I took an initial shot at it, but it's beyond my programming ability.
 - 3bb) In floor collision, we're looking at a 2d plane. In Cylinder Collision we need to look at it from 3 dimensions.
 - 3cc) Another aspect of this is the floor collision should reflect in an upward direction. Cylinder collision needs to look at the angle between the two end points to define the perpendicular. From there gravity will affect the cube as normal. 
 - 3dd) Another key aspect is using the defined radius and plotting the contact zone out in a line based on the end points. 
 - 3ee) I'd imagine if you could implement a cylinder, a sphere would be easy. Squares and rectangles would be the same basic concepts. 
 - 4) Resolve contact and collision are both implemented. cube bounces off the floor and spring forces seem to work as appropriate. From what i have, there isn't a good way to test this. If I've implemented a flawed model, especially over multiple components it's even harder to define if what i have if valid. 
 - 5) Extra springs are added, but incorrectly based on initial implementation. will try to implement using the hint posted on Piazza. It though implement shear springs from x to X+1,y+1 and x to X-1,y-1 without going outside of the bounds of the cube. Bend springs could implement as x to X+2, or y to Y+2
 - 6) Currently have not added additional features. Plan to add a video of my bouncing cube, unsure if there are other items i can implement
 - 6.1) Going to add notes here for any of the extra features, and ideas on how they could have been implemented. 
 - 6a) Cube and Sphere ideas listed above within point 3. One of the interesting videos i saw which implemented this was where a cube fell between two spheres and had a smushing effect. 
 - 6b) We've really only implemented gravity and reflected force through springs. To generate this point you would need to implement a new forces which affects user chosen particles.
 - 6c) Same as above, but with a push effect. If implemented well, could base force generated based on mouse movements angry birds style, or as building forces based on duration of mouse click. 
 - 6d) This could be a secondary ground plane. Assign a mesh to it. Could turn into a sort of slide effect. Potentially assign multiple overlapping cylinders and let cylinders collision handle the mechanics. 
 - 6e) Unsure how to implement.
 - 6f) Unsure how to implement. Likely involves spawning a second cube at a new location, then iterating over the second cubes particles on every pass. maybe a for loop around your main section where you resolve the world and contacts for each cube. 
 - 6g) more stable integration methods would likely further slow down the cube. Not sure what any of these integration methods are. 
 - 6h) Short video of the cube reacting in Part 5 below
 - 6i) I took a couple more videos using different settings. these are listed in Part 5 below.
 - 6j) Unsure how to implement. 
 - 6k) --
 
 
 ## Part 3 - Written Questions
 - 1) Ks and Kd refer to the stiffness and damping effects granted to a spring. As Ks increases, you generate more kinetic force within the spring. As Kd increases it grants a higher damping effect to reduce kinetic force from the spring. As Ks increases you get more bounciness. As Kd increase it resets back to a static position faster. Each value has a tipping point. If Kd is too high, it damps the kinetic force before it can do anything. If Ks is too high you have too much reactive force. 
 - 2) The additional checks are expensive. A potentially better way to handle it would be to use RK1 initially until you hit a closer epsilon and then convert to rk2 until you get to a closer epsilon then convert to rk4. I think this method was explained with the bunny, we do specific checks based on our area based on what we expect to interact with. 
 - 3) Bridge physics simulation. Any sort of combined material simulator, like maybe the effect of hurricane force winds on the exterior of a building. Hair, grass and cloth were all linked within the course. 
 - 4) The jello cube behaves realistically as far as gravity is concerned. With better implemented springs and collision models i would expect it to react realistically as well. The various spring constants might need additional tuning to resolve conflicts. I chose RK4 method. When using RK1 or RK2 the cube would destabilize and explode given enough time. 
 - 5) Link the molecules together, use a low Ks and minimal Kd. Implement some sort of penalty for friction. Water has unique properties which would need to be accounted for. 
 
 ## Part 4 - Final Report
Not sure what to put for the final report. Many of the items listed within the requirements are covered above. If possible and appropriate, I'd like to use this area for feedback. This was a difficult assignment. In the late 90s I worked for a .com as a system's administrator and did a lot of script level coding both as part of my duties and also for customer deliverables. As part of the job I picked up a foundation in C, but moved to PERL because of ease of use. While this gave me a leg up when working with the cube, it wasn't enough to feel comfortable. Many of these items were a struggle both to conceptualize, as well as convert from logic out to code in a language I'd never coded in. While I've never considered myself a programmer, I'm good at data manipulation. With data, I know what I want to do and how to make regular expressions to get there. But this project was far outside of my normal scope. 
Not intended as a criticism, but when I think about the assignment, I feel for those with lower levels of programming skill it might be better to come at the cube as a semester project where you work towards implementing sections of the code on a weekly basis. In the begining of class we were taking small steps forward and building on our successes, but with the homework it seemed like it went from small steps to a giant vertical leap. 

I know one of the areas I struggled in was needing to implement the floor, then collision just to see an effect. I'm very much a trial and error type person. By not seeing the floor I struggled over a lack of positive errors to learn from. Lesson learned, ask for help earlier. 

On a more positive note: this homework made me think more about simulation and how it works. I (like a think a lot of people in the course) play games. Recently while playing the current Hitman, I started thinking of it more as an environmental simulator. I started looking at the hows and whys of how the environment reacted and it felt more intuitive and if anything made it more interesting. I think our third assignment covers agent based simulation, and might add more to this. 

I worked with a couple of students on concept level stuff in the course. I honestly wished I had the opportunity to collaborate directly with more people from the course. 

Additionally, the guidance out of piazza was awesome. I was hopelessly stuck on the forces equation until the framework was posted. 
I used Symbolab to generate my integral. it's a neat site which does step by step for most math functions and also will markup your equations into LaTeX.

I asked one of my programmer friends to help out, but as I was explaining the code and the requirements I realized how it would take on his part reading and figuring out what I was doing to help out. :) I really didnt want it to turn into his homework assignement just to help me out. 

I know there are un-implemented items within the cube, but I'm confortable with where it's at. Last night, I showed my SO the video where the cube seems to teleport off the screen and she grinned. That's good enough for me. :)

That's all I've got. 



## Part 5 - Extra Credit
| Title  | File |
| ------------- | ------------- |
| Bouncing Jello | [files/jello_bounce.mp4]   [File-g] |
| Jello using standard settings and RK4 |  |
| Sproing Jello | [files/sproing.mp4]   [File-h] |
| Jello using 20000 Ks and 5 Kd |  |
| Stiff Jello | [files/stiff.mp4]   [File-i] |
| Jello using 1000 Ks and 50 Kd|  |
| RK1 Floor Implode Jello | [files/rk1.mp4]   [File-j] |
| Jello using RK1 |  |

   [File-g]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/jello_bounce.mp4>
   [File-h]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/sproing.mp4>
   [File-i]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/stiff.mp4>
   [File-j]: <https://github.com/timmons1234/IDS6938-SimulationTechniques/tree/master/Homework1/files/rk1.mp4>



