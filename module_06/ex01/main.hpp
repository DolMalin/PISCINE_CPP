#pragma once

# include <iostream>
# include <stdint.h>

# include "Data.hpp"

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);