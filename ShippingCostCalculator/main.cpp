#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int length {},height {}, width {};
    
    const int tier1Threshold {
        100
    };
    const int tier2Threshold {
        500
    };
    
    int maxDimension {10};
    double baseCost {2.50};
    double tier1Surcharge {0.10};
    double tier2Surcharge {0.25};

    cout << "Welcome to the Shipping Cost Calculator!" << endl;
    cout << "We ship everything with any package's dimension under 10 inches." << endl;
    cout << "Enter length, height and width of the packages separeted with spaces: " << endl;
    cin >> length >> height >> width;

    if (length > maxDimension || height > maxDimension || width > maxDimension) {
        cout << "Sorry we cannot ship your package. Check your dimensions." << endl;
    } else {

        int volume = length * height * width;
        double totalCost {0};

        if(volume >= tier2Threshold) {
            totalCost = baseCost + (baseCost * tier2Surcharge);
            cout << "Adding " << tier2Surcharge * 100 << "% extra cost on your shipping because of it surpasses tier 2 threshold." << endl;
        } else if(volume >= tier1Threshold) {
            totalCost = baseCost + (baseCost * tier1Surcharge);
            cout << "Adding " << tier1Surcharge * 100 << "% extra cost on your shipping because of it surpasses tier 1 threshold." << endl;
        } else {
            totalCost = baseCost;
        }
        
        //iomanip library set decimals precision
        cout << fixed << setprecision(2);
        cout << "Your package volume is: " << volume << endl;
        cout << "The total cost is: " << totalCost << " euros."<< endl;

    }

    return 0;
}
