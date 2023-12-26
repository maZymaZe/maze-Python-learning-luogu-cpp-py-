class Solution {
   public:
    bool checkOverlap(int radius,
                      int xCenter,
                      int yCenter,
                      int x1,
                      int y1,
                      int x2,
                      int y2) {
        int tx, ty;
        if (xCenter < x1)
            tx = x1;
        else if (xCenter > x2)
            tx = x2;
        else
            tx = xCenter;
        if (yCenter < y1)
            ty = y1;
        else if (yCenter > y2)
            ty = y2;
        else
            ty = yCenter;
        return (xCenter - tx) * (xCenter - tx) +
                   (yCenter - ty) * (yCenter - ty) <=
               radius * radius;
    }
};