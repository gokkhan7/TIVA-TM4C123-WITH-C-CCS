/*  
 * Created by SharpDevelop.  
 * User: gkhn1
 * Date: 13.12.2024  
 * Time: 12:12  
 *   
 * To change this template use Tools | Options | Coding | Edit Standard Headers.  
 */  
namespace SerialPortApp  
{  
    partial class MainForm  
    {  
        /// <summary>  
        /// Designer variable used to keep track of non-visual components.  
        /// </summary>  
        private System.ComponentModel.IContainer components = null;  

        /// <summary>  
        /// Disposes resources used by the form.  
        /// </summary>  
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>  
        protected override void Dispose(bool disposing)  
        {  
            if (disposing)  
            {  
                if (components != null)  
                {  
                    components.Dispose();  
                }  
            }  
            base.Dispose(disposing);  
        }  

        /// <summary>  
        /// This method is required for Windows Forms designer support.  
        /// Do not change the method contents inside the source code editor. The Forms designer might  
        /// not be able to load this method if it was changed manually.  
        /// </summary>  
        private void InitializeComponent()  
        {  
            this.components = new System.ComponentModel.Container();  
            this.labelComPort = new System.Windows.Forms.Label();  
            this.textComPort = new System.Windows.Forms.TextBox();  
            this.buttonOpen = new System.Windows.Forms.Button();  
            this.labelBaudRate = new System.Windows.Forms.Label();  
            this.textBaudRate = new System.Windows.Forms.TextBox();  
            this.buttonClose = new System.Windows.Forms.Button();  
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);  
            this.labelDataBits = new System.Windows.Forms.Label();  
            this.textDataBits = new System.Windows.Forms.TextBox();  
            this.labelDataToSend = new System.Windows.Forms.Label();  
            this.textDataToSend = new System.Windows.Forms.TextBox();  
            this.buttonSendToMC = new System.Windows.Forms.Button();  
            this.labelReceivedData = new System.Windows.Forms.Label();  
            this.textReceivedData = new System.Windows.Forms.TextBox();  
            this.labelStartTime = new System.Windows.Forms.Label();  
            this.textStartTime = new System.Windows.Forms.TextBox();  
            this.buttonSendTime = new System.Windows.Forms.Button();  
            this.labelADCData = new System.Windows.Forms.Label();  
            this.textADCData = new System.Windows.Forms.TextBox();  
            this.labelLCD = new System.Windows.Forms.Label();  
            this.textMCReceived = new System.Windows.Forms.TextBox();  
            this.SuspendLayout();  
            //   
            // labelComPort  
            //   
            this.labelComPort.Location = new System.Drawing.Point(28, 42);  
            this.labelComPort.Name = "labelComPort";  
            this.labelComPort.Size = new System.Drawing.Size(100, 32);  
            this.labelComPort.TabIndex = 0;  
            this.labelComPort.Text = "COM Port";  
            //   
            // textComPort  
            //   
            this.textComPort.Location = new System.Drawing.Point(259, 42);  
            this.textComPort.Name = "textComPort";  
            this.textComPort.Size = new System.Drawing.Size(100, 22);  
            this.textComPort.TabIndex = 1;  
            this.textComPort.Text = "COM3";  
            //   
            // buttonOpen  
            //   
            this.buttonOpen.Location = new System.Drawing.Point(440, 42);  
            this.buttonOpen.Name = "buttonOpen";  
            this.buttonOpen.Size = new System.Drawing.Size(75, 23);  
            this.buttonOpen.TabIndex = 2;  
            this.buttonOpen.Text = "Open";  
            this.buttonOpen.UseVisualStyleBackColor = true;  
            this.buttonOpen.Click += new System.EventHandler(this.ButtonOpenClick);  
            //   
            // labelBaudRate  
            //   
            this.labelBaudRate.Location = new System.Drawing.Point(28, 112);  
            this.labelBaudRate.Name = "labelBaudRate";  
            this.labelBaudRate.Size = new System.Drawing.Size(100, 23);  
            this.labelBaudRate.TabIndex = 3;  
            this.labelBaudRate.Text = "Baud Rate";  
            //   
            // textBaudRate  
            //   
            this.textBaudRate.Location = new System.Drawing.Point(259, 112);  
            this.textBaudRate.Name = "textBaudRate";  
            this.textBaudRate.Size = new System.Drawing.Size(100, 22);  
            this.textBaudRate.TabIndex = 4;  
            this.textBaudRate.Text = "115200";  
            //   
            // buttonClose  
            //   
            this.buttonClose.Location = new System.Drawing.Point(440, 112);  
            this.buttonClose.Name = "buttonClose";  
            this.buttonClose.Size = new System.Drawing.Size(75, 23);  
            this.buttonClose.TabIndex = 5;  
            this.buttonClose.Text = "Close";  
            this.buttonClose.UseVisualStyleBackColor = true;  
            this.buttonClose.Click += new System.EventHandler(this.ButtonCloseClick);  
            //   
            // serialPort1  
            //   
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPort1DataReceived);  
            //   
            // labelDataBits  
            //   
            this.labelDataBits.Location = new System.Drawing.Point(28, 180);  
            this.labelDataBits.Name = "labelDataBits";  
            this.labelDataBits.Size = new System.Drawing.Size(100, 23);  
            this.labelDataBits.TabIndex = 6;  
            this.labelDataBits.Text = "Data Bits";  
            //   
            // textDataBits  
            //   
            this.textDataBits.Location = new System.Drawing.Point(259, 181);  
            this.textDataBits.Name = "textDataBits";  
            this.textDataBits.Size = new System.Drawing.Size(100, 22);  
            this.textDataBits.TabIndex = 7;  
            this.textDataBits.Text = "8";  
            //   
            // labelDataToSend  
            //   
            this.labelDataToSend.Location = new System.Drawing.Point(28, 286);  
            this.labelDataToSend.Name = "labelDataToSend";  
            this.labelDataToSend.Size = new System.Drawing.Size(118, 44);  
            this.labelDataToSend.TabIndex = 8;  
            this.labelDataToSend.Text = "Data to Send";  
            //   
            // textDataToSend  
            //   
            this.textDataToSend.Location = new System.Drawing.Point(201, 260);  
            this.textDataToSend.Multiline = true;  
            this.textDataToSend.Name = "textDataToSend";  
            this.textDataToSend.Size = new System.Drawing.Size(185, 78);  
            this.textDataToSend.TabIndex = 9;  
            this.textDataToSend.Text = "This will be displayed on line 1 of the LCD";  
            //   
            // buttonSendToMC  
            //   
            this.buttonSendToMC.Location = new System.Drawing.Point(440, 266);  
            this.buttonSendToMC.Name = "buttonSendToMC";  
            this.buttonSendToMC.Size = new System.Drawing.Size(75, 72);  
            this.buttonSendToMC.TabIndex = 10;  
            this.buttonSendToMC.Text = "Send to MC";  
            this.buttonSendToMC.UseVisualStyleBackColor = true;  
            this.buttonSendToMC.Click += new System.EventHandler(this.ButtonSendToMCClick);  
            //   
            // labelReceivedData  
            //   
            this.labelReceivedData.Location = new System.Drawing.Point(28, 434);  
            this.labelReceivedData.Name = "labelReceivedData";  
            this.labelReceivedData.Size = new System.Drawing.Size(100, 23);  
            this.labelReceivedData.TabIndex = 11;  
            this.labelReceivedData.Text = "Received Data";  
            //   
            // textReceivedData  
            //   
            this.textReceivedData.Location = new System.Drawing.Point(201, 431);  
            this.textReceivedData.Multiline = true;  
            this.textReceivedData.Name = "textReceivedData";  
            this.textReceivedData.Size = new System.Drawing.Size(228, 43);  
            this.textReceivedData.TabIndex = 12;  
            //   
            // labelStartTime  
            //   
            this.labelStartTime.Location = new System.Drawing.Point(28, 528);  
            this.labelStartTime.Name = "labelStartTime";  
            this.labelStartTime.Size = new System.Drawing.Size(100, 23);  
            this.labelStartTime.TabIndex = 13;  
            this.labelStartTime.Text = "Start Time";  
            //   
            // textStartTime  
            //   
            this.textStartTime.Location = new System.Drawing.Point(201, 528);  
            this.textStartTime.Name = "textStartTime";  
            this.textStartTime.Size = new System.Drawing.Size(175, 22);  
            this.textStartTime.TabIndex = 14;  
            this.textStartTime.Text = "12:34:56";  
            //   
            // buttonSendTime  
            //   
            this.buttonSendTime.Location = new System.Drawing.Point(457, 506);  
            this.buttonSendTime.Name = "buttonSendTime";  
            this.buttonSendTime.Size = new System.Drawing.Size(75, 62);  
            this.buttonSendTime.TabIndex = 15;  
            this.buttonSendTime.Text = "Send Time";  
            this.buttonSendTime.UseVisualStyleBackColor = true;  
            this.buttonSendTime.Click += new System.EventHandler(this.ButtonSendTimeClick);  
            //   
            // labelADCData  
            //   
            this.labelADCData.Location = new System.Drawing.Point(28, 619);  
            this.labelADCData.Name = "labelADCData";  
            this.labelADCData.Size = new System.Drawing.Size(100, 23);  
            this.labelADCData.TabIndex = 16;  
            this.labelADCData.Text = "ADC Data";  
            //   
            // textADCData  
            //   
            this.textADCData.Location = new System.Drawing.Point(201, 619);  
            this.textADCData.Name = "textADCData";  
            this.textADCData.Size = new System.Drawing.Size(158, 22);  
            this.textADCData.TabIndex = 17;  
            //   
            // labelLCD  
            //   
            this.labelLCD.Location = new System.Drawing.Point(29, 700);  
            this.labelLCD.Name = "labelLCD";  
            this.labelLCD.Size = new System.Drawing.Size(100, 23);  
            this.labelLCD.TabIndex = 18;  
            this.labelLCD.Text = "LCD";  
            //   
            // textMCReceived  
            //   
            this.textMCReceived.Location = new System.Drawing.Point(201, 701);  
            this.textMCReceived.Name = "textMCReceived";  
            this.textMCReceived.Size = new System.Drawing.Size(175, 22);  
            this.textMCReceived.TabIndex = 19;  
            //   
            // MainForm  
            //   
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);  
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;  
            this.ClientSize = new System.Drawing.Size(573, 790);  
            this.Controls.Add(this.textMCReceived);  
            this.Controls.Add(this.labelLCD);  
            this.Controls.Add(this.textADCData);  
            this.Controls.Add(this.labelADCData);  
            this.Controls.Add(this.buttonSendTime);  
            this.Controls.Add(this.textStartTime);  
            this.Controls.Add(this.labelStartTime);  
            this.Controls.Add(this.textReceivedData);  
            this.Controls.Add(this.labelReceivedData);  
            this.Controls.Add(this.buttonSendToMC);  
            this.Controls.Add(this.textDataToSend);  
            this.Controls.Add(this.labelDataToSend);  
            this.Controls.Add(this.textDataBits);  
            this.Controls.Add(this.labelDataBits);  
            this.Controls.Add(this.buttonClose);  
            this.Controls.Add(this.textBaudRate);  
            this.Controls.Add(this.labelBaudRate);  
            this.Controls.Add(this.buttonOpen);  
            this.Controls.Add(this.textComPort);  
            this.Controls.Add(this.labelComPort);  
            this.Name = "MainForm";  
            this.Text = "Serial Port Application";  
            this.ResumeLayout(false);  
            this.PerformLayout();  
        }  
        private System.Windows.Forms.TextBox textMCReceived;  
        private System.Windows.Forms.Label labelLCD;  
        private System.Windows.Forms.TextBox textADCData;  
        private System.Windows.Forms.Label labelADCData;  
        private System.Windows.Forms.Button buttonSendTime;  
        private System.Windows.Forms.TextBox textStartTime;  
        private System.Windows.Forms.Label labelStartTime;  
        private System.Windows.Forms.TextBox textReceivedData;  
        private System.Windows.Forms.Label labelReceivedData;  
        private System.Windows.Forms.Button buttonSendToMC;  
        private System.Windows.Forms.TextBox textDataToSend;  
        private System.Windows.Forms.Label labelDataToSend;  
        private System.Windows.Forms.TextBox textDataBits;  
        private System.Windows.Forms.Label labelDataBits;  
        private System.IO.Ports.SerialPort serialPort1;  
        private System.Windows.Forms.Button buttonClose;  
        private System.Windows.Forms.TextBox textBaudRate;  
        private System.Windows.Forms.Label labelBaudRate;  
        private System.Windows.Forms.Button buttonOpen;  
        private System.Windows.Forms.TextBox textComPort;  
        private System.Windows.Forms.Label labelComPort;  
    }  
}