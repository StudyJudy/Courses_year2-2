#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// ƽ���ϵ�һ����
struct Point 
{
    double x;
    double y;
    bool operator<(const Point& other) const 
    {
        return x < other.x;
    }
};
// ���������ŷ����þ���ƽ��
double distance(const Point& p1, const Point& p2) 
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}
// ��������������
/*pair<double, pair<Point, Point>> bruteForce(const vector<Point>& points, int l, int r)
{
    double minDist = numeric_limits<double>::max();
    pair<Point, Point> closestPoints;
    for (int i = l; i <= r; i++) 
    {
        for (int j = i + 1; j <= r; j++) 
        {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) 
            {
                minDist = dist;
                closestPoints = { points[i], points[j] };
            }
        }
    }
    return { minDist, closestPoints };
}*/
// ���������������в���������
    pair<double, pair<Point, Point>> closestPairRec(const vector<Point>& points, int l, int r) 
    {
    if (l == r) 
    {
        // ֻ��һ���㣬����Ϊ������
        return { numeric_limits<double>::max(), {points[l], points[l]} };
    }
    else if (r - l == 1) 
    {
        // �������㣬ֱ�Ӽ������
        return { distance(points[l], points[r]), {points[l], points[r]} };
    }
    // �ֱ�ݹ鴦��������������
    int mid = (l + r) / 2;
    auto leftClosest = closestPairRec(points, l, mid);
    auto rightClosest = closestPairRec(points, mid + 1, r);
    // ȡ���������о�����С��һ�Ե�
    double minDist;
    pair<Point, Point> closestPoints;
    if (leftClosest.first < rightClosest.first) 
    {
        minDist = leftClosest.first;
        closestPoints = leftClosest.second;
    }
    else 
    {
        minDist = rightClosest.first;
        closestPoints = rightClosest.second;
    }
    // �ڱ߽������в��Ҿ�������ĵ��
    vector<Point> strip;
    for (int i = l; i <= r; i++) 
    {
        if (abs(points[i].x - points[mid].x) < minDist) 
        {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](const Point& p1, const Point& p2) {return p1.y < p2.y; });
    for (int i = 0; i < strip.size(); i++) 
    {
        for (int j = i + 1; j < strip.size() && j <= i + 7; j++) 
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
                closestPoints = { strip[i], strip[j] };
            }
        }
    }
    return { minDist, closestPoints };
    }

    // �ҵ�������
    pair<double, pair<Point, Point>> closestPair(const vector<Point>& points) 
    {
        // �Ȱ���x��������
        vector<Point> sortedPoints = points;
        sort(sortedPoints.begin(), sortedPoints.end());
        // ʹ�õݹ��㷨�ҵ�������
        return closestPairRec(sortedPoints, 0, sortedPoints.size() - 1);
    }
    int main() 
    {
        // �����ĸ���
        int n;
        cin >> n;
        // �������е������
        vector<Point> points(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> points[i].x >> points[i].y;
        }
        // �ҵ������Բ�������
        auto closest = closestPair(points);
        cout << closest.first << endl;
        /*cout << closest.second.first.x << " " << closest.second.first.y << endl;
        cout << closest.second.second.x << " " << closest.second.second.y << endl;*/
        return 0;
    }