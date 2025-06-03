#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t;  i++) {
        double x1, y1, z1, x2, y2, z2, x, y, z;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x >> y >> z;
        
        double ax = x - x1;
        double ay = y - y1;
        double az = z - z1;
        double bx = x2 - x1;
        double by = y2 - y1;
        double bz = z2 - z1;
        
        double dot = ax * bx + ay * by + az * bz;
        double len_sq = bx * bx + by * by + bz * bz;
        double t;
        
        if (len_sq == 0.0) t = 0.0;
        else {
            t = dot / len_sq;
            if (t < 0.0) t = 0.0;
            else if (t > 1.0) t = 1.0;
        }
        
        double closest_x = x1 + t * bx;
        double closest_y = y1 + t * by;
        double closest_z = z1 + t * bz;
        
        double dx = x - closest_x;
        double dy = y - closest_y;
        double dz = z - closest_z;
        
        double distance = sqrt(dx * dx + dy * dy + dz * dz);
        
        cout << "Case " << i << ": ";
        if (distance == floor(distance)) {
            cout << (int)distance;
        } else {
            cout << fixed << setprecision(10) << distance;
        }
        cout << endl;
    }
    return 0;
}