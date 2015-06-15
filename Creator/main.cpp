#include<fstream>
#include<string>
using namespace std;
ofstream fout("homework.xml");
class homework
{
	private:
		int subjectNum = 2;
	public:
		void print()
		{ 
			fout << "<homework>\n";
			for (int i = 0; i < subjectNum; i++)
				subject[i].print();
			fout << "</homework>\n";
		}
		class subject
		{	
			private:
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
			private:
				int chapterNum; 
				chapter __chapter[2];
			public:
				void print()
				{
					string subjectName="adsf";
					fout << "\t<subject name=\"" << subjectName << "\">";
					for (int i = 0; i < chapterNum; i++)
						__chapter[i].print();
					fout << "\t</subject>\n";
				}
		};
	subject subject[2];
};

int main()
{
	homework homework1;
	homework1.print();
	return 0;
}