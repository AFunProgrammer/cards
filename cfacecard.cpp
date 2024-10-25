#pragma once
#include "cfacecard.h"

#include <iostream>

CCard cards[] =
{
    { eFaceCard::AceOfClovers,    "clover",   "ace",    QRect(0,0,148,229)        },
    { eFaceCard::TwoOfClovers,    "clover",   "two",    QRect(148,0,148,229)      },
    { eFaceCard::ThreeOfClovers,  "clover",   "three",  QRect(295,0,148,229)      },
    { eFaceCard::FourOfClovers,   "clover",   "four",   QRect(443,0,148,229)      },
    { eFaceCard::FiveOfClovers,   "clover",   "five",   QRect(591,0,148,229)      },
    { eFaceCard::SixOfClovers,    "clover",   "six",    QRect(738,0,148,229)      },
    { eFaceCard::SevenOfClovers,  "clover",   "seven",  QRect(886,0,148,229)      },
    { eFaceCard::EightOfClovers,  "clover",   "eight",  QRect(1034,0,148,229)     },
    { eFaceCard::NineOfClovers,   "clover",   "nine",   QRect(1181,0,148,229)     },
    { eFaceCard::TenOfClovers,    "clover",   "ten",    QRect(1329,0,148,229)     },
    { eFaceCard::JackOfClovers,   "clover",   "jack",   QRect(1477,0,148,229)     },
    { eFaceCard::QueenOfClovers,  "clover",   "queen",  QRect(1624,0,148,229)     },
    { eFaceCard::KingOfClovers,   "clover",   "king",   QRect(1772,0,148,229)     },
    { eFaceCard::AceOfDiamonds,   "diamond",  "ace",    QRect(0,230,148,229)      },
    { eFaceCard::TwoOfDiamonds,   "diamond",  "two",    QRect(148,230,148,229)    },
    { eFaceCard::ThreeOfDiamonds, "diamond",  "three",  QRect(295,230,148,229)    },
    { eFaceCard::FourOfDiamonds,  "diamond",  "four",   QRect(443,230,148,229)    },
    { eFaceCard::FiveOfDiamonds,  "diamond",  "five",   QRect(591,230,148,229)    },
    { eFaceCard::SixOfDiamonds,   "diamond",  "six",    QRect(738,230,148,229)    },
    { eFaceCard::SevenOfDiamonds, "diamond",  "seven",  QRect(886,230,148,229)    },
    { eFaceCard::EightOfDiamonds, "diamond",  "eight",  QRect(1034,230,148,229)   },
    { eFaceCard::NineOfDiamonds,  "diamond",  "nine",   QRect(1181,230,148,229)   },
    { eFaceCard::TenOfDiamonds,   "diamond",  "ten",    QRect(1329,230,148,229)   },
    { eFaceCard::JackOfDiamonds,  "diamond",  "jack",   QRect(1477,230,148,229)   },
    { eFaceCard::QueenOfDiamonds, "diamond",  "queen",  QRect(1624,230,148,229)   },
    { eFaceCard::KingOfDiamonds,  "diamond",  "king",   QRect(1772,230,148,229)   },
    { eFaceCard::AceOfHearts,     "heart",    "ace",    QRect(0,460,148,229)      },
    { eFaceCard::TwoOfHearts,     "heart",    "two",    QRect(148,460,148,229)    },
    { eFaceCard::ThreeOfHearts,   "heart",    "three",  QRect(295,460,148,229)    },
    { eFaceCard::FourOfHearts,    "heart",    "four",   QRect(443,460,148,229)    },
    { eFaceCard::FiveOfHearts,    "heart",    "five",   QRect(591,460,148,229)    },
    { eFaceCard::SixOfHearts,     "heart",    "six",    QRect(738,460,148,229)    },
    { eFaceCard::SevenOfHearts,   "heart",    "seven",  QRect(886,460,148,229)    },
    { eFaceCard::EightOfHearts,   "heart",    "eight",  QRect(1034,460,148,229)   },
    { eFaceCard::NineOfHearts,    "heart",    "nine",   QRect(1181,460,148,229)   },
    { eFaceCard::TenOfHearts,     "heart",    "ten",    QRect(1329,460,148,229)   },
    { eFaceCard::JackOfHearts,    "heart",    "jack",   QRect(1477,460,148,229)   },
    { eFaceCard::QueenOfHearts,   "heart",    "queen",  QRect(1624,460,148,229)   },
    { eFaceCard::KingOfHearts,    "heart",    "king",   QRect(1772,460,148,229)   },
    { eFaceCard::AceOfSpades,     "spades",   "ace",    QRect(0,690,148,229)      },
    { eFaceCard::TwoOfSpades,     "spades",   "two",    QRect(148,690,148,229)    },
    { eFaceCard::ThreeOfSpades,   "spades",   "three",  QRect(295,690,148,229)    },
    { eFaceCard::FourOfSpades,    "spades",   "four",   QRect(443,690,148,229)    },
    { eFaceCard::FiveOfSpades,    "spades",   "five",   QRect(591,690,148,229)    },
    { eFaceCard::SixOfSpades,     "spades",   "six",    QRect(738,690,148,229)    },
    { eFaceCard::SevenOfSpades,   "spades",   "seven",  QRect(886,690,148,229)    },
    { eFaceCard::EightOfSpades,   "spades",   "eight",  QRect(1034,690,148,229)   },
    { eFaceCard::NineOfSpades,    "spades",   "nine",   QRect(1181,690,148,229)   },
    { eFaceCard::TenOfSpades,     "spades",   "ten",    QRect(1329,690,148,229)   },
    { eFaceCard::JackOfSpades,    "spades",   "jack",   QRect(1477,690,148,229)   },
    { eFaceCard::QueenOfSpades,   "spades",   "queen",  QRect(1624,690,148,229)   },
    { eFaceCard::KingOfSpades,    "spades",   "king",   QRect(1772,690,148,229)   },
    { eFaceCard::WhiteCard,       "none",     "blank",  QRect(0,920,148,229)      },
    { eFaceCard::BackFace,        "none",     "back",   QRect(295,920,148,229)    }
};

QVector<CCard> CCard::SetupCards()
{
    QVector<CCard> arrayOfCards;
    QPixmap cardDeck;
    bool bQPixmapLoad = cardDeck.load("//home/grandma/Documents/projects/qt/Cards/carddeck.png");
    std::cout << "Did face card deck load succeed: " << (bQPixmapLoad ? "yes" : "no" ) << std::endl;

    int iCardArraySize = sizeof(cards)/sizeof(CCard);

    for( int iCard = 0; iCard < iCardArraySize; iCard++ )
    {
        //get each card face image
        int iWidth = cards[iCard]._loc.width() / 2;
        int iHeight = cards[iCard]._loc.height() / 2;
        cards[iCard]._pImage = new QPixmap(cardDeck.copy(cards[iCard]._loc));//.scaled(iWidth, iHeight, Qt::KeepAspectRatio));

        //append card to list
        arrayOfCards.append(cards[iCard]);
    }

    return arrayOfCards;
}
