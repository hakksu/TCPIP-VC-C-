namespace TcpIP_Client
{
   partial class Form1
   {
      /// <summary>
      /// Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose(bool disposing)
      {
         if (disposing && (components != null))
         {
            components.Dispose();
         }
         base.Dispose(disposing);
      }

      #region Windows Form Designer generated code

      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      private void InitializeComponent()
      {
            this.Con1 = new System.Windows.Forms.Button();
            this.txtData = new System.Windows.Forms.TextBox();
            this.send1 = new System.Windows.Forms.Button();
            this.dis1 = new System.Windows.Forms.Button();
            this.txtIP = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtPort = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtPort2 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtIP2 = new System.Windows.Forms.TextBox();
            this.dis2 = new System.Windows.Forms.Button();
            this.send2 = new System.Windows.Forms.Button();
            this.txtData2 = new System.Windows.Forms.TextBox();
            this.button6 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Con1
            // 
            this.Con1.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Con1.Location = new System.Drawing.Point(85, 160);
            this.Con1.Name = "Con1";
            this.Con1.Size = new System.Drawing.Size(118, 35);
            this.Con1.TabIndex = 0;
            this.Con1.Text = "Connect";
            this.Con1.UseVisualStyleBackColor = true;
            this.Con1.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // txtData
            // 
            this.txtData.Location = new System.Drawing.Point(239, 171);
            this.txtData.Name = "txtData";
            this.txtData.Size = new System.Drawing.Size(100, 22);
            this.txtData.TabIndex = 3;
            // 
            // send1
            // 
            this.send1.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.send1.Location = new System.Drawing.Point(85, 211);
            this.send1.Name = "send1";
            this.send1.Size = new System.Drawing.Size(118, 35);
            this.send1.TabIndex = 4;
            this.send1.Text = "Send Data";
            this.send1.UseVisualStyleBackColor = true;
            this.send1.Click += new System.EventHandler(this.btnSend_Click);
            // 
            // dis1
            // 
            this.dis1.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.dis1.Location = new System.Drawing.Point(85, 263);
            this.dis1.Name = "dis1";
            this.dis1.Size = new System.Drawing.Size(118, 35);
            this.dis1.TabIndex = 5;
            this.dis1.Text = "Disconnect";
            this.dis1.UseVisualStyleBackColor = true;
            this.dis1.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // txtIP
            // 
            this.txtIP.Location = new System.Drawing.Point(130, 132);
            this.txtIP.Name = "txtIP";
            this.txtIP.Size = new System.Drawing.Size(100, 22);
            this.txtIP.TabIndex = 6;
            this.txtIP.Text = "192.168.0.102";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(73, 135);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 12);
            this.label1.TabIndex = 7;
            this.label1.Text = "伺服器IP";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(100, 107);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(24, 12);
            this.label2.TabIndex = 9;
            this.label2.Text = "Port";
            // 
            // txtPort
            // 
            this.txtPort.Location = new System.Drawing.Point(130, 104);
            this.txtPort.Name = "txtPort";
            this.txtPort.Size = new System.Drawing.Size(100, 22);
            this.txtPort.TabIndex = 8;
            this.txtPort.Text = "18887";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(237, 107);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 10;
            this.label3.Text = "1024~65535";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(648, 107);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 19;
            this.label4.Text = "1024~65535";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(511, 107);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(24, 12);
            this.label5.TabIndex = 18;
            this.label5.Text = "Port";
            // 
            // txtPort2
            // 
            this.txtPort2.Location = new System.Drawing.Point(541, 104);
            this.txtPort2.Name = "txtPort2";
            this.txtPort2.Size = new System.Drawing.Size(100, 22);
            this.txtPort2.TabIndex = 17;
            this.txtPort2.Text = "18888";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(484, 135);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(51, 12);
            this.label6.TabIndex = 16;
            this.label6.Text = "伺服器IP";
            // 
            // txtIP2
            // 
            this.txtIP2.Location = new System.Drawing.Point(541, 132);
            this.txtIP2.Name = "txtIP2";
            this.txtIP2.Size = new System.Drawing.Size(100, 22);
            this.txtIP2.TabIndex = 15;
            this.txtIP2.Text = "192.168.0.102";
            // 
            // dis2
            // 
            this.dis2.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.dis2.Location = new System.Drawing.Point(496, 263);
            this.dis2.Name = "dis2";
            this.dis2.Size = new System.Drawing.Size(118, 35);
            this.dis2.TabIndex = 14;
            this.dis2.Text = "Disconnect";
            this.dis2.UseVisualStyleBackColor = true;
            this.dis2.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // send2
            // 
            this.send2.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.send2.Location = new System.Drawing.Point(496, 211);
            this.send2.Name = "send2";
            this.send2.Size = new System.Drawing.Size(118, 35);
            this.send2.TabIndex = 13;
            this.send2.Text = "Send Data";
            this.send2.UseVisualStyleBackColor = true;
            this.send2.Click += new System.EventHandler(this.btnSend_Click);
            // 
            // txtData2
            // 
            this.txtData2.Location = new System.Drawing.Point(650, 171);
            this.txtData2.Name = "txtData2";
            this.txtData2.Size = new System.Drawing.Size(100, 22);
            this.txtData2.TabIndex = 12;
            // 
            // button6
            // 
            this.button6.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.button6.Location = new System.Drawing.Point(496, 160);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(118, 35);
            this.button6.TabIndex = 11;
            this.button6.Text = "Connect";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtPort2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txtIP2);
            this.Controls.Add(this.dis2);
            this.Controls.Add(this.send2);
            this.Controls.Add(this.txtData2);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtPort);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtIP);
            this.Controls.Add(this.dis1);
            this.Controls.Add(this.send1);
            this.Controls.Add(this.txtData);
            this.Controls.Add(this.Con1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

      }

      #endregion

      private System.Windows.Forms.Button Con1;
      private System.Windows.Forms.TextBox txtData;
      private System.Windows.Forms.Button send1;
      private System.Windows.Forms.Button dis1;
        private System.Windows.Forms.TextBox txtIP;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtPort;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtPort2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtIP2;
        private System.Windows.Forms.Button dis2;
        private System.Windows.Forms.Button send2;
        private System.Windows.Forms.TextBox txtData2;
        private System.Windows.Forms.Button button6;
    }
}

