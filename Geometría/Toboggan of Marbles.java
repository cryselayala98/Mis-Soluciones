import java.util.*;

/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3927*/
class Point {

    double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    
	
}

class Line {

    double m, b;
    Point p;  
    Point q;
    static double EPS = 1e-6;

    public Line(double m, double b) {
        this.m = m;
        this.b = b;
    }

    public Line(Point p1, Point p2) {
        this.p=p1;
        this.q=p2;
        m = (p2.y - p1.y) / (p2.x - p1.x);
        b = p2.y - m * p2.x;
    }
    
    int cmp(double x, double y) {
	  return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

    double distanceToPoint(Point r) {
    	
    	Point A =new Point( r.x - q.x, r.y - q.y);
	Point B =new Point(r.x - p.x, r.y - p.y);
	Point C =new Point(q.x - p.x, q.y - p.y);
	
	double a = A.x * A.x + A.y * A.y;
	double b = B.x * B.x + B.y * B.y;
	double c = C.x * C.x + C.y * C.y;
        
	double u=0.0;

	if (cmp(b, a + c) >= 0) u = Math.sqrt(a);
	else if (cmp(a, b + c) >= 0)u=  Math.sqrt(b);
	else u=Math.abs(A.x * B.y - A.y * B.x) / Math.sqrt(c);
	

	return u;

    }
}

 public class Main {

    public static void main(String[] args) {

        double xi, xf, yi, yf;
        int t, l, h;
        ArrayList<Point> puntosI = new ArrayList<>();
        ArrayList<Point> puntosF = new ArrayList<>();
        ArrayList<Line> lineas = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            puntosF.clear();
            puntosI.clear();
            lineas.clear();
            t = sc.nextInt();
            l = sc.nextInt();
            h = sc.nextInt();
            for (int i = 0; i < t; i++) {
                if (i % 2 == 0) {
                    xi = 0.0;
                } else {
                    xi = l;
                }
                yi = sc.nextDouble();
                xf = sc.nextDouble();
                yf = sc.nextDouble();
                puntosF.add(new Point(xf, yf));
                puntosI.add(new Point(xi, yi));
                lineas.add(new Line(new Point(xi, yi), new Point(xf, yf)));
            }

            double minDistance = Double.MAX_VALUE;

            for (int i = 0; i < t; i++) {
            	
                if (i % 2 == 0) {
                    xi = l;
                } else {
                    xi = 0.0;
                }

                double m = Math.abs(puntosF.get(i).x - xi);
                minDistance = Math.min(minDistance, m);

                if (i != 0) {
                	
                        m = lineas.get(i).distanceToPoint(puntosF.get(i - 1));
                        minDistance = Math.min(minDistance, m);
                        
		m = lineas.get(i).distanceToPoint(puntosI.get(i - 1));
                        minDistance = Math.min(minDistance, m);
                        
		m = lineas.get(i-1).distanceToPoint(puntosF.get(i));
                        minDistance = Math.min(minDistance, m);
                        
                        m = lineas.get(i-1).distanceToPoint(puntosI.get(i));
                        minDistance = Math.min(minDistance, m);
                   }
                
            }
            
            System.out.printf("%.2f\n", minDistance);

        }

    }

}
