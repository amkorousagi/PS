#include <iostream>
#include <vector>

typedef struct xy {
    int x;
    int y;
} xy;

typedef struct point {
    int x;
    int y;
    int depth;
} point;


// 2 dimension array -> from low depth to hiht depth
// when find answer, break and initialize everything
// a kind of queue?

using namespace std;
int n;
int s_size = 2;
int s_eat = 0;
int cnt = 0;
vector<vector<int>> space;
vector<vector<bool>> space_check;
vector<vector<struct xy>> que;


point search(int x, int y, int depth) {
    //cout << x <<" "<< y <<" "<< depth << endl;
    point res;
    res.x = 0;
    res.y = 0;
    res.depth = 0;
    if (x < 0 || x >= n || y < 0 || y >= n)
        return res;
    if (space_check[x][y])
        return res;
    space_check[x][y] = true;
    cnt++;
    if (space[x][y] > s_size)
        return res;

    if (space[x][y] > 0 && space[x][y] < s_size) {
        res.x = x;
        res.y = y;
        res.depth = depth;
        return res;
    }

    xy p0 = { x, y + 1 };
    xy p1 = { x + 1,y };
    xy p2 = { x, y - 1 };
    xy p3 = { x - 1, y };
    if (depth + 1 < n*n+1) {
        que[depth + 1].push_back(p0);
        que[depth + 1].push_back(p1);
        que[depth + 1].push_back(p2);
        que[depth + 1].push_back(p3);
    }
    return res;
}


int main(void) {
    cin >> n;
    xy s;
    space.assign(n, vector<int>(n));
    space_check.assign(n, vector<bool>(n, false));
    que.assign(n*n+1, vector<struct xy>(0));

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
           cin>>space[i][j];
           if (space[i][j] == 9) {
               s.x = i;
               s.y = j;
               space[i][j] = 0;
           }
        }
    }
    bool end = false;
    bool re;
    point p;
    int time = 0;
    int depth = 0;
    vector<struct point> res;
    point* real_res = NULL;
    while (!end) {
        //cout << "s " << s.x << s.y << endl;
        re = false;
        search(s.x, s.y, 0);
        depth = 1;
        while (!re) {
            if (depth >= n * n + 1) {
                end = true;
                re = true;
                break;
             }
            while (que[depth].size()) {
                //cout << "que" << que[depth].size() << endl;
                p = search(que[depth].back().x, que[depth].back().y, depth);
                que[depth].pop_back();
                if (p.depth != 0) {
                    //find it
                    res.push_back(p);
                    //cout << "res 후보" << p.x << " " << p.y << " " << p.depth << endl;
                }else if (cnt >= n * n&&res.size()==0) {
                    //cout << "over!" << endl;
                    end = true;
                    re = true;
                    break;
                }
            }
            if (res.size() == 0) {
                depth++;
                continue;
            }
            real_res = &res[0];
            for (int i = 1; i < res.size();i++) {
                if (real_res->x < res[i].x) {
                    continue;
                }
                else if (real_res->x > res[i].x) {
                    real_res = &res[i];
                    continue;
                }
                else {
                    if (real_res->y > res[i].y) {
                        real_res = &res[i];
                    }
                }
            }
            //cout << "p" << p.x << p.y << p.depth << endl;
            p = *real_res;
            //cout << "진짜 res" << p.x << " " << p.y << " " << p.depth << endl;
            time += p.depth;
            s.x = p.x;
            s.y = p.y;
            space[s.x][s.y] = 0;
            s_eat++;
            if (s_eat == s_size) {
                //cout << "level up!" << endl;
                s_size++;
                s_eat = 0;
            }
            space_check.assign(n, vector<bool>(n, false));
            que.assign(n * n + 1, vector<struct xy>(0));
            res.clear();
            re = true;
            cnt = 0;
            real_res = NULL;
        }
    }
    cout << time;
    return 0;
}