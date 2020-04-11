#pragma once
class Student
{
	private:
		char * Name;
		float MathGrade,EnglishGrade,HistoryGrade;

	public:
		Student();
		char* getName();
		void setName(const char *Input);

		float getMathGrade();
		void setMathGrade(float Input);
		float getEnglishGrade();
		void setEnglishGrade(float Input);
		float getHistoryGrade();
		void setHistoryGrade(float Input);

		float average();


};

