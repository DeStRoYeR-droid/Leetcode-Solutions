// Last updated: 06/07/2026, 18:50:36
class Spreadsheet {
    vector<map<int, int>> cols;
public:
    Spreadsheet(int rows) {
        cols = vector<map<int, int>>(26);
    }
    
    void setCell(string cell, int value) {
        int cell_no = stoi(cell.substr(1));
        cols[cell[0] - 'A'][cell_no] = value;
    }
    
    void resetCell(string cell) {
        int cell_no = stoi(cell.substr(1));
        cols[cell[0] - 'A'][cell_no] = 0;
    }
    
    int getValue(string formula) {
        int pSign = formula.find('+');

        int x, y;
        if (formula[1] >= 'A'){
            int cell_no = stoi(formula.substr(2, pSign));
            x = cols[formula[1] - 'A'][cell_no];
        }
        else{
            x = stoi(formula.substr(1, pSign - 1));
        }

        if (formula[pSign + 1] >= 'A'){
            int cell_no = stoi(formula.substr(pSign + 2));
            y = cols[formula[pSign + 1] - 'A'][cell_no];
        }
        else{
            y = stoi(formula.substr(pSign + 1));
        }

        return x + y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */