#include <iostream>
#include <string>

using namespace std;

class RollOver
{
		private:
			int id, advisor, advisee;
			string name, level, major, department;
			double GPA;

		public: 
			RollOver();
			RollOver(int m_id, string m_name, string m_level, string m_major, double m_GPA, int m_advisor);
			RollOver(int m_id, string m_name, string m_level, string m_department, m_advisee)
			~RollOver();
			
};