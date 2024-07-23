# מטלה 3 - קטאן
נטע כהן
netaco432@gmail.com
במטלה זו מימשתי את המשחק קטאן בC++ עבור 3 שחקנים.

## חוקי המשחק
המשחק מורכב מלוח המכיל 19 חלקות אדמה מוקפות בים. כל חלקת אדמה נותנת משאב כלשהו (חוץ מהמדבר). חלקות האדמה במשחק הן: יער (מניב עץ), גבעות (מניבות לבנים), אדמת מרעה (מניבה צמר), אדמה חקלאית (מניבה שיבולת), הרים (מניבים ברזל), מדבר (לא מניב כלום).
כל חלקי המפה מקבלים מספר כלשהו בין 2 ל-12. 
### קלפים, יישובים, ערים ומשאבים
כל שחקן בעל משאבים (כגון שיבולת, ברזל, לבנים וכו') יכול לרכוש איתם דברים שונים במשחק כמו קלפי פיתוח, יישובים, ערים ודרכים.
- קלף פיתוח: מחירו של קלף פיתוח הוא ברזל 1, צמר 1 ושיבולת 1. השחקן יכול לקבל אחד מ-3 סוגים שונים של קלפים: 1. קלף קידום: זהו קלף המעניק הטבה לשחקן (לאחר מכן הקלף נעלם). בין הקלפים הללו ניתן למצוא: מונופול - השחקן בוחר משאב כלשהו וכל שאר השחקנים מחוייבים להעביר לו את המשאב הזה. בניית דרכים - השחקן יכול לבנות 2 דרכים במפה ללא עלות. שנת שפע - השחקן זוכה לקבל מהבנק שני קלפים של משאבים לבחירה ולהשתמש בהם באותו התור. 2. אבירים - שחקן המחזיק ב-3 קלפים כאלה, מקבל את קלף הצבא הגדול ביותר המקנה לו 2 נקודות ניצחון (אם איבד אביר אחד, הקלף נלקח מהשחקן. שימו לב שיש בדיוק 3 קלפים כאלה!). 3. קלפי נקודות ניצחון - יש 4 קלפים שונים המעניקים נקודת ניצחון למי שמחזיק בהם.
- בנייה: ניתן לבנות דרכים, ערים ויישובים בצורה הבאה: 1. קטע דרך: עלותו לבנים 1 ועץ 1. קטע דרך יכול להיות מחובר רק ליישוב (או עיר) בבעלות השחקן או לקטע דרך נוסף. 2. יישוב: עלות היישוב היא לבנה 1, עץ 1, צמר 1 ושיבולת 1. ניתן לבנות יישוב על צומת שאליה מובילה דרך אחת לפחות ומברחק של 2 קטעי דרך מיישוב אחר. בניית יישוב מקנה לשחקן נקודת ניצחון אחת. 3. עיר: עיר יכולה להחליף יישוב קיים. עלות הבנייה היא ברזל 3 ושיבולת 2. ברגע שמשדרגים יישוב לעיר, השחקן מאבד את הנקודה של היישוב ומקבל 2 נקודות על הבנייה. עיר מעניקה לשחקן פי-2 יותר משאבים מכל חבלי הארץ הסמוכים לה.
- משאבים: כאמור, המשאבים מתקבלים מחבלי הארץ השונים. כאשר שחקן מטיל את קוביות המשחק, כל השחקנים מקבלים משאבים בהתאם למספר שיצא בהטלה (כלומר אם יצא 3 בהטלה, אז שחקנים עם יישובים/ערים הגובלים עם חבלי ארץ בעלי אותו מספר זוכים במשאב).
- מסחר: שחקנים יכולים לבצע מסחר ביניהם (כלומר להחליף קלפים או משאבים) בהתאם לאיך שהם קובעים.
### מהלך המשחק
כל שחקן מתחיל את המשחק עם 2 יישובים ו-2 קטעי דרך המעניקים לו 2 נקודות ניצחון. בנוסף, השחקנים מקבלים משאבים התחלתיים בהתאם למקומות שבהם הם מיקמו את היישובים (משאב אחד מכל משאב אפשרי).
סדר המשחק נקבע באופן שרירותי (לשיקולכם). בכל תור השחקנים מטילים 2 קוביות. בהתאם לתוצאת ההטלה, השחקנים מקבלים משאבים כמו שפורט מקודם.
שחקן בתור נתון עושה את הפעולות הבאות לפי הסדר (לאחר הטלת הקוביות):
- הוא יכול לסחור (כלומר להחליף קלפים או משאבים).
- הוא יכול לבנות דרכים, יישובים או ערים ויכול לקנות קלפי פיתוח.
  אם השחקן מנצל את אחד מקלפי הפיתוח שברשותו, התור אוטומטית עובר לשחקן הבא (השחקן יכול לנצל את קלף הפיתוח עוד לפני הטלת הקוביות, במקרה כזה התור עובר לשחקן הבא).
  אם סכום ההטלה הוא 7, על כל השחקנים בעלי יותר מ-7 קלפי משאבים לבחור מחצית מהקלפים ולהחזיר אותם לערימה.
  ### סיום המשחק
  המשחק מסתיים בתור שבו אחד השחקנים הגיע ל-10 או יותר נקודות ניצחון. כדי לנצח במשחק, השחקן צריך שיגיע תורו ובאותו התור יהיו לו 10 נקודות לכל הפחות.

## המחלקות שהגדרתי
המחלקה Catan אחראית על כל הפעולות האפשריות לביצוע במהלך המשחק. היא מחזיקה שלושה שחקנים, לוח משחק, ומצביע שאחראי על המעקב אחרי התורים.
המחלקה Player אחראית על שחקן בודד במשחק. היא מחזיקה את השם שלו, כמויות המשאבים שברשותו, רשימת יישובים וערים, רשימת דרכים ורשימת קלפי פיתוח. 
המחלקה Board אחראית על לוח המשחק, ודרכה יוצרים לוח חדש לשימוש במשחק. 
כל צומת בלוח ממוספר, וכשבונים יישובים, ערים ודרכים מציינים את מספרי הצמתים בהם רוצים לבנות.
הלוח שמור בעזרת וקטור 5*5 של מצביע לLand כך שלא כל התאים בו מנוצלים
המחלקה Land אחראית על חלקה בלוח המשחק ומחזיקה את סוג החלקה והמספר שלה.
המחלקה Settlement אחראית על יישובים וערים הקיימים בלוח. היא מחזיקה את הקוד של הצומת בה קיים היישוב/העיר, רשימה של חלקות האדמה שסביבה 
ומשתנה בוליאני שאומר האם זה יישוב או עיר.
המחלקה Road אחראית על הדרכים הקיימות בלוח ויש בה שני קודי צמתים שלפיהם נדע בדיוק היכן הדרך ממוקמת.
