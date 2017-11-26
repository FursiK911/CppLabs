using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Emgu.CV;
using Emgu.CV.UI;
using Emgu.Util;
using Emgu.CV.CvEnum;
using Emgu.CV.Structure;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        //Создаем объект myCapture который отвечает за перехват
        Capture myCapture = new Capture();
        public Form1()
        {
            InitializeComponent();
        }
 
        private void GetVideo(object sender, EventArgs e)
        {
            //Берем кадр
            Image<Bgr, Byte> Kadr = myCapture.QueryFrame();
            //Вставляем в imageBox
            pictureBox1.Image = Kadr;
        }
 
        private void Form1_Load(object sender, EventArgs e)
        {
            //Делаем это безпрерывно
            Application.Idle += GetVideo;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
