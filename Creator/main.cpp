#include<fstream>
using namespace std;
ofstream fout("homework.xml");
class homework
{
	public:
		void print()
		{ 
			fout << "<homework>\n";
			for (int i = 0; i < subjectNum; i++)
				subject[i].print();
			fout << "</homework>";
		}
	private:
		int subjectNum=2;
		class subject
		{
			
			public:
				void print()
				{
					string subjectName="adsf";
					fout << "\t<subject name=\"";
					fout << subjectName;
				}
			private:
				class chapter
				{
					public:
						void print()
						{

						}
					private:
						class ques
						{
							public:
								void print()
								{

								}
						};
				};
		};
	subject subject[2];
};

int main()
{
	homework homework1;
	homework1.print();
	return 0;
}