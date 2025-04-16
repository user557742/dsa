#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> p2d;
#define X first
#define Y second
const double ss=1e-12;
double cross(p2d a,p2d b){
    return a.X*b.Y-a.Y*b.X;
}
p2d timgiao(p2d a,p2d b,p2d u,p2d v){
    p2d ab={b.X-a.X,b.Y-a.Y};
    p2d uv={v.X-u.X,v.Y-u.Y};
    p2d au={u.X-a.X,u.Y-a.Y};
    double goc=cross(ab,uv);
    if(goc==0) return {1e12,1e12};
    double t=cross(au,uv) /goc;
    return {a.X+t*ab.X,a.Y+t*ab.Y};
}
bool check(p2d X,p2d a,p2d b,p2d c){
    p2d ab={b.X-a.X,b.Y-a.Y};
    p2d ac={c.X-a.X,c.Y-a.Y};
    double Sabc=0.5*abs(cross(ab,ac));
    p2d Xa={a.X-X.X,a.Y-X.Y};
    p2d Xb={b.X-X.X,b.Y-X.Y};
    p2d Xc={c.X-X.X,c.Y-X.Y};
    double SXac=0.5*abs(cross(Xa,Xc));
    double SXab=0.5*abs(cross(Xb,Xa));
    double SXbc=0.5*abs(cross(Xb,Xc));
    return (SXab+SXac+SXbc-Sabc)<=ss;
}
bool trongdoan(p2d x, p2d a, p2d b) {
    double cp = cross({b.X - a.X, b.Y - a.Y}, {x.X - a.X, x.Y - a.Y});
    if (fabs(cp) > ss) return false;
    if (x.X < min(a.X, b.X) - ss || x.X > max(a.X, b.X) + ss) return false;
    if (x.Y < min(a.Y, b.Y) - ss || x.Y > max(a.Y, b.Y) + ss) return false;
    return true;
}
int main(){
    p2d A,B,C,D,E;
    cin>>A.X>>A.Y>>B.X>>B.Y>>C.X>>C.Y;
    cin>>D.X>>D.Y>>E.X>>E.Y;
    p2d X1=timgiao(D,E,A,B);
    p2d X2=timgiao(D,E,B,C);
    p2d X3=timgiao(D,E,C,A);

    vector<p2d> ok;
    if(check(X1,A,B,C)&&trongdoan(X1,D,E)) ok.push_back(X1);
    if(check(X2,A,B,C)&&trongdoan(X2,D,E)) ok.push_back(X2);
    if(check(X3,A,B,C)&&trongdoan(X3,D,E)) ok.push_back(X3);
    cout<<fixed;
    cout.precision(9);
    cout<<sqrt((ok[0].X-ok[1].X)*(ok[0].X-ok[1].X)+(ok[0].Y-ok[1].Y)*(ok[0].Y-ok[1].Y));
}