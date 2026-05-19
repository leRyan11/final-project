AI Collaboration Log
Tools used
ChatGPT
A prompt that worked well
"Here is my spec. What is the simplest way to implement this given my existing classes? What are the trade-offs?"
Why it worked: the prompt kept the design focused on the existing BartSnakeGame, BartSnake, ClipperCard, and GameMap classes instead of adding unnecessary new classes.
A prompt that did not work
"Implement the whole feature and all tests at once."
What went wrong: that kind of prompt can produce too much code in one pass, making it harder to explain and easier to miss style drift or weak tests.
How I recovered: I kept the implementation small and separated the spec, class methods, tests, and documentation.
Code I rejected
I rejected random card placement after collection.
Why I rejected it: random placement would make the tests harder to predict, and this assignment does not need randomness yet.
Fresh-conversation review
Applied: kept card respawning deterministic and checked that the new tests assert real score, length, running-state, and card-position outcomes.
Rejected: larger refactors such as adding a separate board manager class, because the feature is small and the current class design is enough.
What I'd do differently next time
I would write the first test before adding any helper methods, then add only the helper methods that the test proves are necessary.
