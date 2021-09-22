using System.Drawing;
using System.Windows.Forms;

namespace Win32Example
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private static void TestDrawing(Graphics graphics)
        {
            var arial12px = new Font("Consolas", 12, FontStyle.Bold);
            var blackBrushPen = new Pen(Brushes.Black);

            graphics.DrawRectangle(blackBrushPen, 100, 100, 240 - 100, 160 - 100);
            graphics.DrawString("Hello World!", arial12px, blackBrushPen.Brush, new Point(115, 120));
            graphics.DrawLines(blackBrushPen, new[]
            {
                new Point(30, 80),
                new Point(80, 130),
                new Point(30,180),
                new Point(310, 180),
                new Point(260, 130),
                new Point(310, 80),
                new Point(30, 80)
            });
        }

        private static void DrawDiagonal(Graphics graphics, Rectangle rectangle)
        {
            var blackBrushPen = new Pen(Brushes.Black);

            graphics.DrawRectangle(blackBrushPen, rectangle);
            graphics.DrawLine(blackBrushPen, rectangle.X, rectangle.Y, rectangle.Width, rectangle.Height);
        }

        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            TestDrawing(e.Graphics);
            // DrawDiagonal(e.Graphics, e.ClipRectangle);
        }
    }
}
