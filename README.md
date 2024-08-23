# C2A

C2A is a continuous collision detection (CCD) library written in C++ for rigid polygon soup models.

[![linux](https://github.com/timow-gh/C2A/actions/workflows/linux.yml/badge.svg)](https://github.com/timow-gh/C2A/actions/workflows/linux.yml)
[![windows](https://github.com/timow-gh/C2A/actions/workflows/windows.yml/badge.svg?branch=master)](https://github.com/timow-gh/C2A/actions/workflows/windows.yml)

## Dependencies
C2A depends on **PQP**.

1. Please download PQP at [here](https://github.com/GammaUNC/PQP).


2. Copy all contents of PQP to a new folder named `PQP` in the root path.


3. Copy the files PQP.sln and PQP.vcproj into PQP folder. 


## About the project 

Only the `release` mode is supported, if you need debug mode, please change as follow:

1. Properities->C/C++->General->Debug Information Format->Program Database 
2. Properities->C/C++->Optimization->Disabled


In ProximityQuery.sln, two projects exist other than PQP:

* **CCDDemo**: the Demo fucntion for showing how to use C2A.lib.

* **C2A**: continous collision detection based on PQP soft package, and form C2A.lib
The main functions are:
	```c++
	C2A_Result C2A_Solve(Transform *trans00, 
						Transform *trans01,  
						 C2A_Model * obj1_tested,
						 Transform *trans10, 
						 Transform *trans11,  
						 C2A_Model * obj2_tested,
						 Transform & trans0, 
						 Transform & trans1, 
						 PQP_REAL &time_of_contact, 
						 int& number_of_iteration, 
						 int & number_of_contact,
						 PQP_REAL th_ca,
						 C2A_TimeOfContactResult& dres)
	//which function is used to execute conservative advancment algorithm
	
	PQP_REAL 
	C2A_QueryTimeOfContact(CInterpMotion *objmotion1, 
						   CInterpMotion *objmotion2,
						   C2A_TimeOfContactResult *res,  
						   C2A_Model *o1, 
						   C2A_Model *o2,
						   PQP_REAL tolerance_d, 
						   PQP_REAL tolerance_t, 
						   int qsize)
	//which function is used to set parameter and call BVTT function for each CA iterative
	
	int 
	C2A_TimeOfContactStep(CInterpMotion *objmotion1, 
				CInterpMotion *objmotion2, 
				C2A_TimeOfContactResult *res,
				PQP_REAL R1[3][3], 
				PQP_REAL T1[3], 
				C2A_Model *o1,
				PQP_REAL R2[3][3], 
				PQP_REAL T2[3], 
				C2A_Model *o2,
				PQP_REAL tolerance_d,
				PQP_REAL tolerance_t,
				int qsize)
	//Controlled CA function by BVTT
	```
 
 
The result of C2A is saved in result folder under root path.


## Demo

To run the demo, you need [GLUT](https://www.opengl.org/resources/libraries/glut/) & [OpenGL](https://www.opengl.org/). Please make sure the **Startup project** is setup correctly to **CCDDemo**. 


## Citation
C2A was presented in **ICRA 2009** and also publisehd in **TVCG 2014**. Please visit our [website](http://graphics.ewha.ac.kr/C2A/) for more details. To cite C2A in your academic research, please use the following bibtex lines:

**TVCG 2014**:
```bib
@ARTICLE{6684141,
  author={Tang, Min and Manocha, Dinesh and Kim, Young J.},
  journal={IEEE Transactions on Visualization and Computer Graphics}, 
  title={Hierarchical and Controlled Advancement for Continuous Collision Detectionof Rigid and Articulated Models}, 
  year={2014},
  volume={20},
  number={5},
  pages={755-766},
  doi={10.1109/TVCG.2013.266}}
```
**ICRA 2009**:
```bib
@INPROCEEDINGS{5152234,
  author={Tang, Min and Kim, Young J. and Manocha, Dinesh},
  booktitle={2009 IEEE International Conference on Robotics and Automation}, 
  title={C2A: Controlled conservative advancement for continuous collision detection of polygonal models}, 
  year={2009},
  volume={},
  number={},
  pages={849-854},
  doi={10.1109/ROBOT.2009.5152234}}
```

## Reference

The project also referenced the follow open sources:
* [SWIFT++](http://www.cs.unc.edu/~geom/SWIFT++/)
* [Bullet Physics lib](http://www.bulletphysics.org/)

## Contact

If you have any questions or find some bugs, please feel free to connect with **Min Tang** by EMail: tangmin@ewha.ac.kr or tangminewha@gmail.com.

