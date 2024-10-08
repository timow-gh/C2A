#include "model.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include <C2A/C2A.h>
#include <C2A/InterpMotion.h>
#include <fstream>
#include <iostream>

#include <C2A/LinearMath.h>

#define GetContactNumber true

using namespace std;

void readXFormFrames(const char *filename1, const char *filename2);
void outputPerformance(const char *filename);
void outputXformTOCs(const char *filename);
struct TransRT {
  PQP_REAL R[3][3];
  PQP_REAL T[3];
};
TransRT xformframes[2][1000];
TransRT xformTOCs[1000];
float tframes[1000];
float tocframes[1000];
float distframes[1000];
int iterframes[1000];
float contframes[1000];
bool collision_flag[1000];

int nframes;
int iframe = 0;
int nTests = 10;

static const char *timingFileName = "../results/timingPQPCCD_Dir.txt";

// PQP_DistanceResult dres;
C2A_TimeOfContactResult dres;

void outputPerformance(const char *filename) {

  ofstream fout(filename);

  fout << endl
       << "Frame No.| Timing |  Iterative |   TOC   |   Distance   | Contact  "
          "| FrontNode";
  fout << endl;

  for (int i = 0; i < nframes - 1; i++) {
    if (tocframes[i] == 0.0)
      fout << i << "   \t " << tframes[i] * 1000 << "   \t " << iterframes[i]
           << "   \t " << tocframes[i] << "    \t " << distframes[i]
           << "      \t " << contframes[i] << endl;
    else
      fout << i << "   \t " << tframes[i] * 1000 << "   \t" << iterframes[i]
           << "   \t " << tocframes[i] << "   \t " << distframes[i]
           << "      \t " << contframes[i] << endl;
  }
  cout << "Stop!" << endl;
}

void outputXformTOCs(const char *filename) {
  ofstream fout(filename);
  TransRT *xform;

  for (int i = 0; i < nframes - 1; i++) {
    xform = &xformTOCs[i];

    fout << i << " " << xform->R[0][0] << " " << xform->R[0][1] << " "
         << xform->R[0][2] << " " << xform->R[1][0] << " " << xform->R[1][1]
         << " " << xform->R[1][2] << " " << xform->R[2][0] << " "
         << xform->R[2][1] << " " << xform->R[2][2] << " " << xform->T[0] << " "
         << xform->T[1] << " " << xform->T[2] << endl;
  }
  cout << "Finish outputting xforms at TOC!" << endl;
}

inline void Transform2PQP(Transform *t, PQP_REAL R[3][3], PQP_REAL T[3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      R[i][j] = t->Rotation()[i][j];
    }
    T[i] = t->Translation()[i];
  }
}

inline void PQP2Transform(PQP_REAL R[3][3], PQP_REAL T[3], Transform &t) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      t.Rotation()[i][j] = R[i][j];
    }
    t.Translation()[i] = T[i];
  }
}
