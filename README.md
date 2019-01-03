# circle_queue
A simple implement circle_queue
When you have a fixed-length queue and have high performance requirements, congratulations, you can use it.

example:
    '''
        CircleQueue<int> circle(10);
        for (int i = 0; i < 100; i++)
        {
            circle.push_back(i);
        }
        for (auto &iter : circle) {
            cout << iter << endl;
        }
    '''
    if you not set construct function param, the lenth is seted 100.
