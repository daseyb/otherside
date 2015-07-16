# otherside
A VM running SPIR-V code on the CPU

This is an implementation of the SPIR-V, the new intermediate language defined by Khronos.  
See the official specification here: [SPIR-V 1.0](https://www.khronos.org/registry/spir-v/specs/1.0/SPIRV.html)

It also produces C like code that represents the given SPIR-V file (for easier reading).

#### Note 
This is very much a work in progress. Not all instructions are implemented and performance has not been a priority so far.

#### Spec Parser
This project downloads the latest spec and generates C++ files with useful declerations from it. Mostly information about  op codes and structs to represent them to help with parsing and processing.

#### Todo

* SPIR-V Validation ([validation rules described here]( https://www.khronos.org/registry/spir-v/specs/1.0/SPIRV.html#_a_id_validation_a_validation_rules))
* Implement all OpCodes
* Improve performance
* Better human readable parsing output (at least match the reference compiler)
