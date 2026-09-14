class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int stX = rec1[0];   // rec1 left
        int stY = rec1[1];   // rec1 bottom
        int enX = rec1[2];   // rec1 right
        int enY = rec1[3];   // rec1 top

        int newstX = rec2[0]; // rec2 left
        int newstY = rec2[1]; // rec2 bottom
        int newenX = rec2[2]; // rec2 right
        int newenY = rec2[3]; // rec2 top

        // Case 1: rec2 completely to the LEFT of rec1
        // (rec2’s right edge is <= rec1’s left edge)
        if (newenX <= stX) return false;

        // Case 2: rec2 completely to the RIGHT of rec1
        // (rec2’s left edge is >= rec1’s right edge)
        if (newstX >= enX) return false;

        // Case 3: rec2 completely BELOW rec1
        // (rec2’s top edge is <= rec1’s bottom edge)
        if (newenY <= stY) return false;

        // Case 4: rec2 completely ABOVE rec1
        // (rec2’s bottom edge is >= rec1’s top edge)
        if (newstY >= enY) return false;

        // If none of the “moved away” cases are true,
        // then rec2 must overlap rec1
        return true;
    }
};
