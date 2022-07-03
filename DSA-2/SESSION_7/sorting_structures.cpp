#include <bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    vector<int> marks;
    int id;
};

bool cmp(Student s1, Student s2){
    vector<int> mark1 = s1.marks;
    vector<int> mark2 = s2.marks;

    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < 5; i++){
        sum1 += mark1[i];
        sum2 += mark2[i];
    }

    if(sum1 == sum2){
        if(s1.name == s2.name){
            return s1.id < s2.id;
        }else{
            return s1.name < s2.name;
        }
    }else{
        return sum1 > sum2;
    }

}


vector<int> marksSort(int n, vector<Student> students){
    sort(students.begin(), students.end(), cmp);
    vector<int> result;

    for(int i = 0; i < students.size(); i++){
        result.push_back(students[i].id);
    }

    return result;
}


int main(){
    int n;
    cin>>n;
    vector<Student> students(n);
    for(auto &std: students){
        cin>>std.id >> std.name;
        std.marks.resize(5);
        for(auto &mark: std.marks){
            cin >> mark;
        }
    }
    vector<int> ids = marksSort(n, students);
    for(auto &id:ids){
        cout<< id << " ";
    }
    return 0;
}