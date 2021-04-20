#include <iostream>
using namespace std;

namespace ImageCentral{
    void createImage(int width, int height)
    {
        cout << "Creating An Image " << endl;
    }
}

using namespace ImageCentral;

int main(){
    createImage(300, 200);

    return 0;
}