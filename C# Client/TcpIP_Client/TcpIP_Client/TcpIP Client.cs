using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TcpIP_Client
{
   public partial class Form1 : Form
   {
      private TcpClient m_client;
      private TcpClient m_client2;

      public Form1()
      {
         InitializeComponent();
      }

      private void btnConnect_Click(object sender, EventArgs e)
      {
         Button btn = (Button)sender;

         try
         {
                if (btn.Name == "Con1")
                {
                    // Create Tcp client.
                    int nPort = Int32.Parse(txtPort.Text);
                    m_client = new TcpClient(txtIP.Text, nPort);
                }
                else
                {
                    int nPort = Int32.Parse(txtPort2.Text);
                    m_client2 = new TcpClient(txtIP2.Text, nPort);
                }
         }
         catch (ArgumentNullException a)
         {
            Console.WriteLine("ArgumentNullException:{0}", a);
         }
         catch (SocketException ex)
         {
            Console.WriteLine("SocketException:{0}", ex);
         }
      }

      private void btnSend_Click(object sender, EventArgs e)
      {
            NetworkStream stream;
            byte[] btData;
            Button btn = (Button)sender;
            try
            {
                if (btn.Name == "send1")
                {
                    stream = m_client.GetStream();
                    btData = System.Text.Encoding.ASCII.GetBytes(txtData.Text); // Convert string to byte array.
                }
                else
                {
                    stream = m_client2.GetStream();
                    btData = System.Text.Encoding.ASCII.GetBytes(txtData2.Text);
                }

                stream.Write(btData, 0, btData.Length); // Write data to server.
            }
            catch (Exception ex)
            {
                Console.WriteLine("Write Exception:{0}", ex);
            }
      }

      private void btnDisconnect_Click(object sender, EventArgs e)
      {
            Button btn = (Button)sender;
            if (btn.Name == "dis1")
                m_client.Close();
            else
                m_client2.Close();
        }
    }
}
