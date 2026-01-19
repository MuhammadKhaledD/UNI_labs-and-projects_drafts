using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace DBapplication
{
    public class Controller
    {
        DBManager dbMan;
        public Controller()
        {
            dbMan = new DBManager();
        }


        public int InsertU(int id, string n, string e, string a)
        {
            string query = $"INSERT INTO Users  (id, first_name, email, address) VALUES ({id}, '{n}', '{e}', '{a}');";
            return dbMan.ExecuteNonQuery(query);
        }

        public int InsertO(int id, int uid, int p, int qty, double tp)
        {
            string query = $"INSERT INTO Orders  (id, user_id, product_id, quantity, total_price) VALUES ({id}, {uid}, {p}, {qty}, {tp});";
            return dbMan.ExecuteNonQuery(query);
        }

        public int Delete()
        {
            string query = "DELETE FROM  WHERE ={};"; ;
            return dbMan.ExecuteNonQuery(query);
        }

        public int Update()
        {
            string query = "UPDATE  SET  ={} WHERE ={};";
            return dbMan.ExecuteNonQuery(query);
        }

        public DataTable SelectAll()
        {
            string query = "SELECT ,  FROM ;"; ;
            return dbMan.ExecuteReader(query);
        }

        public double Select(int id)
        {
            string query = $"SELECT price FROM Products WHERE id = {id};";
            return (double)dbMan.ExecuteScalar(query);
        }


        public DataTable email(string e)
        {
            string query = $"SELECT user_id, product_id, quantity, total_price FROM Orders as o, Users as u WHERE o.user_id = u.id AND u.email = '{e}' ;";
            return dbMan.ExecuteReader(query);
        }

        public DataTable users()
        {
            string query = "SELECT user_id, sum(total_price) as Spendings FROM ORDERS GROUP BY user_id ORDER BY Spendings DESC;";
            return dbMan.ExecuteReader(query);
        }

        public DataTable products()
        {
            string query = "SELECT name, price, description FROM Products;";
            return dbMan.ExecuteReader(query);
        }

        public DataTable productscombo()
        {
            string query = "SELECT id, name FROM Products;";
            return dbMan.ExecuteReader(query);
        }


        public void TerminateConnection()
        {
            dbMan.CloseConnection();
        }
             
    }
}
