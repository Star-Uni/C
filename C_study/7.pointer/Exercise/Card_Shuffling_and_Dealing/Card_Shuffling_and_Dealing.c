#include <stdio.h>
#include <stdlib.h>

void Game(int faces[], char *suits[], int *dealer_win, int *player_win, int *tie);

int main(void){

    srand(4);

    int faces[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};// face = faces[(hand[0]-1)/4]
    char *suits[4] = {"Diamond", "Club", "Heart", "Spade"};// suit = suits[(hand[]-1)%4]

    int dealer_win = 0,player_win = 0,tie = 0;

    for(int i = 0; i < 200; Game(faces,suits,&dealer_win,&player_win,&tie),++i);

    printf("dealer win: %d\nplayer win: %d\ntie: %d\n", dealer_win,player_win,tie);
    return 0;
}

int Deal(int hand[], int faces[], char *suits[]){

    int face[5];
    char *suit[5];

    for(int i = 0; i < 5; ++i){
        face[i] = faces[(hand[i]-1)/4];
        suit[i] = suits[(hand[i]-1)%4];
    }

    if( face[0] == face[1]-1 && 
        face[0] == face[2]-2 && 
        face[0] == face[3]-3 && 
        face[0] == face[4]-4){
        
        if( suit[0] == suit[1] && 
            suit[0] == suit[2] && 
            suit[0] == suit[3] && 
            suit[0] == suit[4]){
        
            return 0;
        }

        return 4;
    }
    else if(suit[0] == suit[1] && 
            suit[0] == suit[2] && 
            suit[0] == suit[3] && 
            suit[0] == suit[4]){

        return 3;
    }
    else if(face[0] == face[1] && 
            face[0] == face[2] && 
            face[0] == face[3] ||
            face[1] == face[2] && 
            face[1] == face[3] && 
            face[1] == face[4]){

        return 1;
    }
    else if(face[0] == face[1] && 
            face[0] == face[2] || 
            face[1] == face[2] && 
            face[1] == face[3] || 
            face[2] == face[3] && 
            face[2] == face[4]){

        if( face[0] == face[1] && 
            face[0] == face[2] &&
            face[3] == face[4] ||
            face[2] == face[3] && 
            face[2] == face[4] &&
            face[0] == face[1]){

            return 2;
        }

        return 5;
    }
    else if(face[0] == face[1] && 
            face[2] == face[3] || 
            face[1] == face[2] && 
            face[3] == face[4] || 
            face[0] == face[1] && 
            face[3] == face[4]){

        return 6;
    }
    else if(face[0] == face[1] ||
            face[1] == face[2] || 
            face[2] == face[3] || 
            face[3] == face[4]){

        return 7;
    }

    return 8;
}

void Shuffle(int card[]){
    
    void Swap(int *a, int *b);

    for(int i = 0;i < 52;++i){

        Swap(&card[i], &card[rand()%(52-i)]);
    }
    
    /*int nums[52];

    for(int i = 0;i < 52;++i){

        nums[i] = rand()%52+1;

        int flag = 0;

        do{
            if(flag){

                nums[i] = rand()%52+1;
                flag = 0;
            }

            for(int j = 0;j < i;++j){

                if(nums[i] == nums[j]){

                    flag = 1;
                    break;
                }
            }
        }while(flag);
    }

    for(int i = 0;i<52;card[i] = nums[i],++i);*/
}

void Sort(int a[], int size){

    void Swap(int *a, int *b);

    for(int i = size;i > 0;--i){

        for(int j = 1;j < i;++j){

            a[j] < a[j-1]?Swap(&a[j],&a[j-1]):114514;
        }
    }
}

void Swap(int *a, int *b){

    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Dealer_Decide(int hand[],int cards[], int faces[], char *suits[]){
    
    void Sort(int a[], int size);

    /* Scarne's Poker Probability Table

    High card: 50.12% (1 in 2)

    Pair: 42.26% (1 in 2.4)

    Two pair: 4.75% (1 in 21)

    Three of a kind: 2.11% (1 in 47)

    Straight: 0.392% (1 in 255)

    Flush: 0.197% (1 in 509)

    Full house: 0.144% (1 in 694)

    Four of a kind: 0.0240% (1 in 4,165)

    Straight flush: 0.00139% (1 in 72,193)
    */
    
    int deal = Deal(hand,faces,suits);

    int face[5];

    for(int i = 0; i < 5;face[i] = faces[(hand[i]-1)/4], ++i);

    switch (deal){
        case 8:{ // High card strategy
        
            /* Strategy:

        Keep 2 or 3 hightest card
        if lack one for flush: keep highest or seek for flush?
        P(Flush | lack 1) = 9/47    
                          = 19.15%

        if lack one for straight: keep highest or seek for straight?
        P(Straight | lack 1 for two side) = 8/47    
                          = 17.02%
        P(Straight | lack 1 for one side or in middle) = 4/47    
                          = 8.51%

        Keep 2:
        P(A Pair ∩ Keep 2) = (6C1 * (41C1 *((32/41)37C1 + (9/41)38C1))/2!)/47C3
                           = 28.23%
        P(Two Pair ∩ Keep 2) = (3C1 * 3C1 * 41C1 + 3C1 * (3 * 3C2 + 8 * 4C2) * 2)/47C3
                             = 4.39
        P(Three of a kind ∩ Keep 2) = (2 * 3C2 * 41C1)/47C3
                                    = 1.52%
        P(Full house ∩ Keep 2) = (2 * 3C2 * 3C1)/47C3
                               = 0.11% 
        P(Four of a kind ∩ Keep 2) = (2 * 3C3)/47C3
                                   = 0.012% 
        total: 34.26%

        Keep 3:
        P(Pair ∩ Keep 3) = (3C1 * 3C1 * 38C1) / 47C2
                         = 31.64%
        P(Two Pair ∩ Keep 3) = (3C2 * 3C1 * 3C1) / 47C2
                             = 2.50%
        P(Three of a kind ∩ Keep 3) = (3C1 * 3C2) / 47C2
                                    =  0.83%
        P(Full house ∩ Keep 3) = 0
        P(Four of a kind ∩ Keep 3) = 0
        total: 34.97%

        Conclusion: Most Stable one is Keep 2/Keep 3 no matter what situation
                    Considering Keep 2 is stronger, choose Keep 2
        */
    
            hand[2] = cards[49];
            hand[3] = cards[50];
            hand[4] = cards[51];

            Sort(hand, 5);

            return;
        }
        case 7:{ // Pair strategy

            // Strategy: Keep the pair

            int pair;
        
            for(int i = 0;i<4;(face[i] == face[i+1])?(pair = i):(1),++i);

            for(int i = 0;i<4;(i == pair || i == pair + 1)?(1):(hand[i] = cards[47+i]),++i);

            Sort(hand, 5);

            return;
        }
        case 6:{ // Two Pair strategy

            // Strategy: Keep the pairs

            int single = 4;
        
            (face[0] == face[1])?(1):(single = 0);
            (face[2] == face[1] || face[2] == face[3])?(1):(single = 2);

            hand[single] = cards[51];

            Sort(hand, 5);

            return;
        }
        case 5:{ // 3 of a kind strategy

            int three;
        
            for(int i = 0;i<4;(face[i] == face[i+1] && face[i] == face[i+2])?(three = i):(1),++i);

            for(int i = 0;i<4;(i == three || i == three + 1 || three + 2)?(1):(hand[i] = cards[47+i]),++i);

            Sort(hand, 5);

            return;
        }
        default:{

            return;
        }
    }
}

void Game(int faces[], char *suits[], int *dealer_win, int *player_win, int *tie){

    char *deal[] = {"Straight Flush", "Four of a kind", "Full house", "Flush", "Straight", "Three of A kind", "Two Pair", "Pair", "High Card"};

    int cards[52];
    for(int i = 0;i < 52;cards[i] = i+1, ++i);

    Shuffle(cards);

    int dealer_hand[] = {cards[1], cards[2], cards[3], cards[4], cards[5]};
    int player_hand[] = {cards[6], cards[7], cards[8], cards[9], cards[10]};

    int dealer,player;

    Sort(dealer_hand, 5);
    Sort(player_hand, 5);

    printf("Dealer's hand before: %s\n", deal[Deal(dealer_hand, faces, suits)]);
    Dealer_Decide(dealer_hand, cards, faces, suits);
    printf("Dealer's hand after: %s\n", deal[dealer = Deal(dealer_hand, faces, suits)]);
    //dealer = Deal(dealer_hand, faces, suits);

    printf("Player's hand: %s\n", deal[player = Deal(player_hand, faces, suits)]);
    //player = Deal(player_hand, faces, suits);

    (dealer < player)?(printf("Dealer win\n\n")):((player < dealer)?(printf("Player win\n\n")):printf("Draw\n\n"));
    (dealer < player)?(*dealer_win += 1):((player < dealer)?(*player_win += 1):(*tie += 1));
}

