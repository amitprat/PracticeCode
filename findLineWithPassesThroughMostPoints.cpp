/*
Given a two dimensional graph with points on it, find a line which passes the most
number of points 
*/

#define EPSILON 0.0001

class Line {
  double slope;
  double intercept;
  public:
  Line(Point a, Point b) {
    if( abs(b.x - a.x) > EPSILON ) {
      slope = (b.y - a.y) / ( b.x - a.x);
      intercept = a.y - slope* a.x;
    } else {
      slope = -1;
      intercept = a.x;  //since the slope is infinite
    }
  }
  bool operator == (Point p) {
    return ( abs(slope  - p.slope) > EPSILON && 
      abs(intercept - p.intercept) > EPSILON );
  }
 };
 
 int main() {
 unordered_map< Line, vector<Point> > m;
  for(int i=0;i<N;i++) {
    for(int j = 0;j <N;j++) {
      Line l = Line(p[i],p[j]);
      m[l].push_back(p[i]);
      m[l].push_back(p[j]);
    }
  }
  Line bestLine;
  int bestCount = 0;
  for(auto p : m) {
    if(p.second.size > bestCount) {
      bestCount = p.second.size;
      bestLine = p.first;
    }
  }
  
  
  print(bestLine, bestCount);
 }
