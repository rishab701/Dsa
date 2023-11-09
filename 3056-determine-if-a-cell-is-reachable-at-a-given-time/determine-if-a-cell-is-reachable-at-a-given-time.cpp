class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int vert_dist = abs(sy-fy);
        int hor_dist  = abs(sx-fx);
        
        if(vert_dist == 0 && hor_dist == 0 && t == 1) {
            return false;
        }
        int min_time=max(hor_dist,vert_dist);
        if(t >= min_time){
            return true;
        }
        return false;
    }
};