#include<fstream>
#include<string>
#include<map>
using namespace std;
ofstream fout("homework.xml");
class ques
{
private:
	int difficulty;
public:
	void queAppend(int __difficulty)
	{
		difficulty = __difficulty;
	}
	void print()
	{
		fout << "\t\t\t\t<difficulty>" << difficulty << "</difficulty>\n";
		fout << "</ques>\n";
	}
};
class chapter
{
private:
	int queNum = 0;
public:
	ques* queHead[100];
	map <int, int> queNo_List;
	map <int, int> queList_No;
	void queAppend(int que_No, int __difficulty)
	{
		queList_No[queNum++] = que_No;
		queNo_List[que_No] = queNum - 1;
		queHead[queNum - 1] = new ques[1];
		queHead[queNum - 1]->queAppend(__difficulty);
	}
	void print(int chapter_No)
	{
		for (int i = 0; i < queNum; i++)
		{
			fout << "\t\t\t<ques>\n";
			fout << "\t\t\t\t<quesNo>" << chapter_No << "." << queList_No[i] << "</quesNo>\n";
			queHead[i]->print();
		}
		fout << "\t\t</chapter>\n";
	}
};
class subject
{
public:
	int chapterNum = 0;
	chapter* chapterHead[100];
	map <int, int> chapterNo_List;
	map<int, int> chapterList_No;
public:
	void chapterAppend(int chapter_No, int que_No, int __difficulty)
	{
		if (chapterNo_List.find(chapter_No) == chapterNo_List.end())
		{
			chapterList_No[chapterNum++] = chapter_No;
			chapterNo_List[chapter_No] = chapterNum - 1;
			chapterHead[chapterNum - 1] = new chapter[1];
			chapterHead[chapterNum - 1]->queAppend(que_No, __difficulty);
		}
		else chapterHead[chapterNo_List[chapter_No]]->queAppend(que_No, __difficulty);
	}
	void print() //print a subject
	{

		for (int i = 0; i < chapterNum; i++)
		{
			fout << "\t\t<chapter No=\"" << chapterList_No[i] << "\">\n";
			chapterHead[i]->print(chapterList_No[i]);
		}
		fout << "\t</subject>\n";
	}
};
class homework
{
private:
	map <int, string> subjectNo_Name;//map subjectName and subjectNo
	map <string, int> subjectName_No;
	int subjectNum = 0;
public:
	void print()  //print homework
	{
		fout << "<homework>\n";
		for (int i = 0; i < subjectNum; i++)
		{
			fout << "\t<subject name=\"" << subjectNo_Name[i] << "\">\n";
			subjectHead[i]->print();
		}
		fout << "</homework>\n";
	}
	void Append(string subject_Name, int chapter_No,int que_No,int __difficulty)  //apply ram for a subject
	{
		if (subjectName_No.find(subject_Name) == subjectName_No.end())
		{
			subjectHead[subjectNum++] = new subject[1];
			subjectName_No[subject_Name] = subjectNum - 1;
			subjectNo_Name[subjectNum - 1] = subject_Name;
			subjectHead[subjectNum - 1]->chapterAppend(chapter_No, que_No, __difficulty);
		}
		else
		{
			subjectHead[subjectName_No[subject_Name]]->chapterAppend(chapter_No, que_No, __difficulty);
		}
	}

private:
	subject* subjectHead[100];//point the head to subject
};

int main()
{
	homework homework1;
	homework1.Append("Math", 1, 1, 2);
	homework1.Append("Math", 1, 2, 5);
	homework1.Append("Math", 2, 4, 5);
	homework1.Append("Programming", 5, 7, 5);
	homework1.print();
	return 0;
}