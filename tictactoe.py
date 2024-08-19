# Define dimensions of the board
rows = 3
columns = 3

# Define a function that initializes an empty 3x3 matrix for the board
def initialize_board():
    board = []
    for i in range(rows):
        # Initialize 'empty' cells with *
        temp = ['*', '*', '*']
        board.append(temp)
    return board

# Define and call a function that prints the board
def print_board(board):
    for i in range(rows):
        print(board[i], '\n')

# Define a function for a player to make a move
def make_move(board, row, column, player):
    message = ''
    out_of_bounds_error = 'Out of bounds error, try again'              # Outside 3x3 grid
    occupation_error = 'This move has already been played, try again'   # Move already been made
    unknown_player_error = 'Unknown player number'                      # Player outside 1 and 2
    success_message = 'Move made successfully'                          # Successful move
    move_made = False

    if row > rows or row < 1 or column > columns or column < 1:
        message += out_of_bounds_error
    elif player != 1 and player != 2:
        message += unknown_player_error
    elif (board[row - 1][column - 1] != '*'):
        message += occupation_error
    else:
        if (player == 1):
            board[row - 1][column - 1] = 'X'
        elif (player == 2):
            board[row - 1][column - 1] = 'O'
        message += success_message
        move_made = True
        
    if move_made:
        print_board(board)

    print(message)
    return move_made

""" 
# Function testing
make_move(board, 3, 3, 1)
make_move(board, 2, 4, 1)
make_move(board, 0, 2, 1)
make_move(board, 3, 3, 3)
make_move(board, 3, 3, 2)
### Should output:
# * * * 
# * * * 
# * * X
# Move made successfully 
# Out of bounds error, try again
# Out of bounds error, try again
# Unknown player number
# This move has already been played, try again
"""

# Define a function to check if the board represents a winning game
def check_win(board, symbol):    
    # Diagonal wins (2 variations)
    diagonal_win_1 = all(board[i][i] == symbol for i in range(rows))
    diagonal_win_2 = all(board[i][columns - 1 - i] == symbol for i in range(rows))

    if diagonal_win_1 or diagonal_win_2:
        return True, symbol

    # Horizontal wins (3 variations)
    for s in range(rows):
        if all(board[s][j] == symbol for j in range(columns)):
            return True, symbol

    # Vertical wins (3 variations)
    for l in range(columns):
        if all(board[t][l] == symbol for t in range(rows)):
            return True, symbol

    # Tie game
    board_full = all(board[p][q] != '*' for p in range(rows) for q in range(columns))
    if board_full:
        return True, 0

    return False, None

# Define a function to output a message given a winner/tie
def final_message(winner):
    if winner == 0:
        print('Tie')
    elif winner == 'X':
        print('Player 1 Wins!')
    elif winner == 'O':
        print('Player 2 Wins!')

# Define a function to simulate the game 
def play_game():
    players = [1,2]
    symbols = ['X', 'O']
    curr = 0

    board = initialize_board()
    print_board(board)

    while(True):
        row = int(input("Input Row (1-3): "))
        column = int(input("Input Column (1-3): "))
        
        # If make_move returns false (move wasn't made), then repeat 
        while not make_move(board, row, column, players[curr]):
            row = int(input("Input Row: "))
            column = int(input("Input Column: "))
        
        # Check if the latest move won the game, if not move on the loop, if so break
        status, symbol = check_win(board, symbols[curr])
        if status:
            final_message(symbol)
            break

        # Alternate between players 
        curr = 1 - curr

# Uncomment the following line to run game
play_game()