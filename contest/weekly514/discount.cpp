class Solution
{
public:
    double minPrice(vector<int> &p, vector<int> &d)
    {
        priority_queue<double> pqD;
        priority_queue<double> pqP;
        for (int num : p)
        {
            pqP.push(num);
        }
        for (int num : d)
        {
            pqD.push(num);
        }
        double res = 0;
        while (!pqD.empty() && (!pqP.empty()))
        {
            double price = pqP.top();
            pqP.pop();
            double dis = pqD.top();
            pqD.pop();
            double curr = (price * (100 - dis)) / 100.0;
            res += curr;
        }
        while (!pqP.empty())
        {
            res += pqP.top();
            pqP.pop();
        }
        return res;
    }
};
