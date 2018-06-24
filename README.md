# Corewar ⚔️🤺

  
computer game, where the gamers write programs/warriors in one of the
	assembler languages (low level language) like Redcode/Bluecode/Corewars. These
	languages create machine code based on source code, that consists of basic
	operations of processor, called an assembly language. The programs/warriors
	run in a special selected section of memory (so-called core) under the thumb
	of a simulator (VS I guess?). A core creates a closed loop - after crossing the
	highest avaliable address, it comes back to the first cell of memory. Two or
	more warriors are entered into teh memory array at randomly chosen positions,
	they don't know the enemies positions. All users take turns, one by one. One
	instruction per each is executed.


## There are three parts Corewar can be broken down into:
* **The assembler**: this program compiles given warriors and translates them from the language understendable for humanity t (nerdly speaking **assembly language**) into the language readable for a virtual machine - **Bytecode**, changing file extention from _.s_ to _.cor_. Moreover, assembly langueage of our choice (we didn't really have any choice) is neither Redcode, nor bluecode nor corewars, but 42code (more info below).
* **The virtual machine**: It’s the “arena” in which your champions will be executed.
It offers various functions, all of which will be useful for the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes;
we are asking you for a gladiator fight, not a one-man show simulator.
* **The champion**: this part is about creating a super powerful warrior that will beat the 💩 out of the other champs and eat them all based on the set of instruction it was given, simultaneously reporting itself as alive.  over, rendering this kind of champion is serious work. And since, for now, we
are mostly interested in your capacity to create Corewar’s other programs (i.e. the
assembler and virtual machine), your current champion will only need to prove to
us that you can write bits and pieces of Corewar ASM. This means that the champion
you should render for this project only needs to scare the bejesus out of a
neurasthenic hedgehog.

The game ends when all the processes are dead. The winner is the last player
reported to be “alive”
