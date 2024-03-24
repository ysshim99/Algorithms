#include <bits/stdc++.h>
using namespace std;

string subjectName, grade; // subjectName: 과목명, grade: 등급
double credit; // credit: 학점

double calcGPA(string grade) {
  if(grade == "F") return 0.0;

  double score = 0.0;
  if(grade[0] == 'A') score = 4.0;
  if(grade[0] == 'B') score = 3.0;
  if(grade[0] == 'C') score = 2.0;
  if(grade[0] == 'D') score = 1.0;

  if(grade[1] == '+') score += 0.5;

  return score;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  double totalScore = 0.0; // 총 학점 * 과목평점의 합
  double totalCredit = 0.0; // 총 학점의 합

  for(int i = 0; i < 20; ++i) {
    cin >> subjectName >> credit >> grade;

    if(grade == "P") continue;

   totalScore += credit * calcGPA(grade);
    totalCredit += credit;
  }
  
  double totalGPA = totalScore / totalCredit; // 전공평점
  cout << totalGPA;
}