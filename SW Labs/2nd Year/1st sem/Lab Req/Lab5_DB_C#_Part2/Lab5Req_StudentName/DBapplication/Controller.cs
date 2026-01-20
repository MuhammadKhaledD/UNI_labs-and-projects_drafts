using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Windows.Forms;

namespace DBapplication
{
    public class Controller
    {
        DBManager dbMan;
        static int PID ;
        public Controller()
        {
            dbMan = new DBManager();
            PID = numP()+1;
        }

        public int InsertPaper(string PTitle, int JournalID)
        {
            string query = $"INSERT INTO Paper (PID, ATitle, JournalID) " +
                           $"VALUES ('{PID}', '{PTitle}', {JournalID});";
            ++PID;
            return dbMan.ExecuteNonQuery(query);
        }

        public DataTable SelectJinfo()
        {
            string query = "SELECT * FROM Journal;";
            return dbMan.ExecuteReader(query);
        }

        public DataTable SelectAllAuthors()
        {
            string query = "SELECT AName, count(AuthorID) AS numberOFPapers FROM Author, Write Where AuthorID = AID GROUP BY AName ORDER BY numberOFPapers DESC;";
            return dbMan.ExecuteReader(query);
        }

        public int SelectPID(string PTitle)
        {
            string query = $"SELECT PID FROM Paper WHERE ATitle = {PTitle};";
            return Convert.ToInt32(query);
        }

        public int Updatepaper(int PID, int JournalID)
        {
            string query = $"UPDATE Paper SET JournalID ={JournalID} WHERE PID={PID};";
            return dbMan.ExecuteNonQuery(query);
        }

        public DataTable papers()
        {
            string query = "SELECT PID, ATitle FROM Paper;";
            return dbMan.ExecuteReader(query);
        }

        public DataTable journal()
        {
            string query = "SELECT JID, JTitle FROM Journal;";
            return dbMan.ExecuteReader(query);
        }

        public int journalid(int pid)
        {
            string query = $"SELECT JournalID FROM Paper WHERE PID = {pid};";
            return Convert.ToInt32(dbMan.ExecuteScalar(query));
        }

        public int numP()
        {
            string query = $"SELECT COUNT(*) FROM Paper;";
            return Convert.ToInt32(dbMan.ExecuteScalar(query)); ;
        }

        public void TerminateConnection()
        {
            dbMan.CloseConnection();
        }

        
             
    }
}
