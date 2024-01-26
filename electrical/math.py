# %% imports
import numpy as np 

# %% Antenna Length

c = 3e8
f = 2.4e9
lambda_ = c/f
L = lambda_ / 4
print('L=', L*100, 'cm')