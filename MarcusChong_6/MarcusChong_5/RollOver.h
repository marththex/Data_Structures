#include <iostream>
#include <string>

using namespace std;

class RollOver
{
		private:
			int id, id2, advisor, undo;
			string name, level, major, department;
			double GPA;

		public: 
			RollOver();
			RollOver(int m_id, string m_name, string m_level, string m_major, double m_GPA, int m_advisor, int m_undo);
			RollOver(int m_id, string m_name, string m_level, string m_department, int m_undo);
			RollOver(int m_id, int m_id2, int m_undo);
			RollOver(int m_id, int m_id2, int m_advisor, int m_undo);
			~RollOver();
			int getID();
			int getID2();
			string getName();
			string getLevel();
			string getMajor();
			double getGPA();
			int getAdvisor();
			string getDepartment();
			int getUndo();
			void setID(int m_id);
			void setID2(int m_id);
			void setName(string m_name);
			void setLevel(string m_level);
			void setMajor(string m_major);
			void setGPA(double m_GPA);
			void setAdvisor(int m_advisor);
			void setDepartment(string m_department);
			void setUndo(int m_undo);
};