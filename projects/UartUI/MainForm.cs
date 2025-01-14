/*  
 * Created by SharpDevelop.  
 * User: gkhn1 
 * Date: 13.12.2024  
 * Time: 12:12  
 *   
 * To change this template use Tools | Options | Coding | Edit Standard Headers.  
 */  
using System;  
using System.Collections.Generic;  
using System.Drawing;  
using System.Windows.Forms;  

namespace SerialPortApp  
{  
    /// <summary>  
    /// Description of MainForm.  
    /// </summary>  
    public partial class MainForm : Form  
    {  
        string receivedData = string.Empty;  

        public MainForm()  
        {  
            //  
            // The InitializeComponent() call is required for Windows Forms designer support.  
            //  
            InitializeComponent();  

            //  
            // TODO: Add constructor code after the InitializeComponent() call.  
            //  
        }  

        void ButtonOpenClick(object sender, EventArgs e)  
        {  
            if (!serialPort1.IsOpen)  
            {  
                serialPort1.PortName = textComPort.Text;  
                serialPort1.BaudRate = Convert.ToInt32(textBaudRate.Text);  
                serialPort1.DataBits = Convert.ToInt32(textDataBits.Text);  
                serialPort1.Open();  
            }  
        }  

        void ButtonCloseClick(object sender, EventArgs e)  
        {  
            if (serialPort1.IsOpen)  
            {  
                serialPort1.Close();  
            }  
        }  

        void ButtonSendToMCClick(object sender, EventArgs e)  
        {  
            serialPort1.Write("[" + textDataToSend.Text + "]");  
        }  

        void SerialPort1DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)  
        {  
            receivedData = serialPort1.ReadLine();  
            this.Invoke(new EventHandler(DisplayText));  
        }  

        private void DisplayText(object sender, EventArgs e)  
        {  
            textReceivedData.Text = receivedData;  
            if (receivedData[0] == '{')  
            {  
                textMCReceived.Text = receivedData.Substring(1, 8);  
            }  
            else if (receivedData[0] == '(')  
            {  
                textADCData.Text = receivedData.Substring(1, 4);  
            }  
            else if (receivedData[0] == '[')  
            {  
                textDataToSend.Text = receivedData;  
            }  
        }  

        void ButtonSendTimeClick(object sender, EventArgs e)  
        {  
            serialPort1.Write("%" + textStartTime.Text + "/");  
        }  
    }  
}