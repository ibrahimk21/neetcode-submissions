class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // 1. Basic Check: If total cards aren't divisible by groupSize, fail immediately.
        if (hand.size() % groupSize != 0) return false;

        // 2. Count frequencies using an Ordered Map
        // The map automatically sorts keys: {1:1, 2:2, 3:2, 4:1, ...}
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // 3. Process the cards
        // Iterate through the map. Since it's ordered, 'it' always points to the smallest available card.
        for (auto it = count.begin(); it != count.end(); ++it) {
            int startCard = it->first;
            int quantity = it->second;

            // If quantity is 0, it means this card was already used up 
            // as part of a previous sequence (e.g., 2 was used by 1-2-3).
            if (quantity > 0) {
                
                // We need to form 'quantity' groups starting with 'startCard'.
                // Example: If we have three 1s, we need to form three sequences of 1-2-3.
                // So we need three 2s and three 3s.
                for (int i = 0; i < groupSize; i++) {
                    int currentCard = startCard + i;
                    
                    // Check if we have enough of the next card needed
                    if (count[currentCard] < quantity) {
                        return false;
                    }
                    
                    // Use the cards
                    count[currentCard] -= quantity;
                }
            }
        }

        return true;
    }
};