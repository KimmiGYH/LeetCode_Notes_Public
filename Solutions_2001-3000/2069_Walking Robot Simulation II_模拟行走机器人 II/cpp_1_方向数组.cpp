class Robot {
public:
    int w, h;
    int x, y, d;
    string dirs[4] = {"East", "North", "West", "South"};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    Robot(int width, int height) {
        w = width; h = height;
        x = y = 0; d = 0;
    }
    
    void step(int num) {
        int perimeter = (w + h - 2) * 2;
        num %= perimeter;
        // 没考虑到的测试点 num == 0
        // !num 不代表在原点，只是某个step为周长的整数倍而已
        if (!num & !x & !y) d = 3;
        while (num--) {
            int newx = x + dx[d], newy = y + dy[d];
            if (newx < 0 || newx >= w || newy < 0 || newy >= h) {
                d++, d %= 4;
                newx = x + dx[d], newy = y + dy[d];
            }
            x = newx, y = newy;
        }
        
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[d];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */