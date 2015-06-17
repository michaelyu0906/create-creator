#include<fstream>
#include<string>
using namespace std;
ofstream fout("homework.xml");
class homework
{
	private:
		int subjectNum;
	public:
		void print()  //print homework
		{ 
			fout << "<homework>\n";
			for (int i = 0; i < subjectNum; i++)
				subjectHead[i]->print();
			fout << "</homework>\n";
		}
		void Appendsubjects(int subject_Num)  //apply ram for subjects
		{
			subjectNum = subject_Num;
			for (int i = 0; i < subjectNum; i++)
				subjectHead[i] = new subject[1];
		}
		class subject
		{	
			private:
				string subjectName;
				int chapterNum; 
				class chapter
				{
					private:
						int queNum;
						class ques
					{
						private:
							int queNo;
							int difficulty;
						public:
						void print(int chapterNo)
						{
							fout << "\t\t\t<ques>\n";
							fout << "\t\t\t\t<quesNo>" << chapterNo << "." << queNo << "</quesNo>\n";
							fout << "\t\t\t\t<difficulty>" << difficulty << "</difficulty>\n";
						}
					};
						ques __ques[2];
					public:
						int chapterNo;
					void print()
					{
						fout << "\t\t<chapter No=\"" << chapterNo << "\">\n";
						for (int i = 0; i < queNum; i++)
							__ques[i].print(chapterNo);
						fout << "\t\t</chapter>\n";
					}
				};
				chapter* chapterHead[100];
			public:
				void subjectDetails(string subject_Name, int chapter_Num)  //apply ram for chapters
				{
					subjectName = subject_Name;
					chapterNum = chapter_Num;
					for (int i = 0; i < chapterNum; i++)
						chapterHead[i] = new chapter[1];
				}
				void print() //print a subject
				{
					fout << "\t<subject name=\"" << subjectName << "\">";
					for (int i = 0; i < chapterNum; i++)
						chapterHead[i]->print();
					fout << "\t</subject>\n";
				}
		};
	private:
		subject* subjectHead[100];//point the head to subject
};

int main()
{
	homework homework1;
	homework1.print();
	return 0;
}