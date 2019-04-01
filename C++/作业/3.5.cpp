#include<iostream>
using namespace std;
class Student{
	public:
		Student(int num,float s):number(n),score(s){}
		int num ;
		float score;
};
void main()
{Student stu[5] = {
	Student(1707004340,100.0),Student(1707004301,60.5),
	Student(1707004342,89.2),Student(1707004341,99.0),
	Student(1707004323,92,1);}
	void max(Student[]);
	Student *p = &stu[0];
	max(p);
	
}
void max(Student *arr)
{
	float max_score = arr[0].score;
	int k = 0;
	for (int i = 0;i < 5;i++)
	{
		if(arr[i].score > max_score)
		{
			max_score = arr[i].score;
			k  = i;
		}
	 } 
	cot<<arr[k].num<<""<<max_score<<endl;
}

