using System;
using System.Collections.Generic;
using System.Data;

namespace lab4
{
    public class Controller
    {
        DBManager dbMan;

        public Controller()
        {
            dbMan = new DBManager();
        }

        public int InsertEmp(string fname, string lname, string address, string ssn, int dno)
        {
            // Ensure SSN is numeric
            if (!long.TryParse(ssn, out long ssnNum))
            {
                return 0;
            }

            string query = $"INSERT INTO Employee (Fname, Lname, SSN, Address, Dno) " +
                           $"VALUES ('{fname}', '{lname}', {ssnNum}, '{address}', {dno});";
            return dbMan.ExecuteNonQuery(query);
        }

        public int DeleteEmp(string ssn)
        {
            if (!long.TryParse(ssn, out long ssnNum))
                return 0;

            string query = $"DELETE FROM Employee WHERE SSN={ssnNum};";
            return dbMan.ExecuteNonQuery(query);
        }

        public int UpdateHours(string ssn, string pnumber, int hours)
        {
            if (!long.TryParse(ssn, out long ssnNum) || !int.TryParse(pnumber, out int pNum))
                return 0;

            string query = $"UPDATE Works_On SET Hours={hours} WHERE Essn={ssnNum} AND Pno={pNum};";
            return dbMan.ExecuteNonQuery(query);
        }

        public DataTable SelectAllEmployee()
        {
            string query = "SELECT * FROM Employee;";
            return dbMan.ExecuteReader(query);
        }

        public double Counthours(int s)
        {
            string query = $"SELECT SUM(Hours) FROM Works_On WHERE Pno={s};";
            object result = dbMan.ExecuteScalar(query);
            if (result == DBNull.Value || result == null) return 0;
            return Convert.ToDouble(result);
        }

        public void TerminateConnection()
        {
            dbMan.CloseConnection();
        }

        public int[] GetIntArrayFromDB()
        {
            List<int> numbers = new List<int>();
            string query = "SELECT Pnumber FROM Project;";
            DataTable dt = dbMan.ExecuteReader(query);

            if (dt != null)
            {
                foreach (DataRow row in dt.Rows)
                {
                    if (int.TryParse(row["Pnumber"].ToString(), out int num))
                        numbers.Add(num);
                }
            }

            return numbers.ToArray();
        }
    }
}
