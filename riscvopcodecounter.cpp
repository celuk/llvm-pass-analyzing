#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;
/*
enum op{

    enumbeq = 1             
    ,enumbne               
    ,enumblt               
    ,enumbge               
    ,enumbltu              
    ,enumbgeu              
    ,enumjalr              
    ,enumjal               
    ,enumlui               
    ,enumauipc             
    ,enumaddi              
    ,enumslli              
    ,enumslti              
    ,enumsltiu             
    ,enumxori              
    ,enumsrli              
    ,enumsrai              
    ,enumori               
    ,enumandi              
    ,enumadd               
    ,enumsub               
    ,enumsll               
    ,enumslt               
    ,enumsltu              
    ,enumxor_              
    ,enumsrl               
    ,enumsra               
    ,enumor_               
    ,enumand_              
    ,enumaddiw             
    ,enumslliw             
    ,enumsrliw             
    ,enumsraiw             
    ,enumaddw              
    ,enumsubw              
    ,enumsllw              
    ,enumsrlw              
    ,enumsraw              
    ,enumlb                
    ,enumlh                
    ,enumlw                
    ,enumld                
    ,enumlbu               
    ,enumlhu               
    ,enumlwu               
    ,enumsb                
    ,enumsh                
    ,enumsw                
    ,enumsd                
    ,enumfence             
    ,enumfence_i           
    ,enummul               
    ,enummulh              
    ,enummulhsu            
    ,enummulhu             
    ,enumdiv               
    ,enumdivu              
    ,enumrem               
    ,enumremu              
    ,enummulw              
    ,enumdivw              
    ,enumdivuw             
    ,enumremw              
    ,enumremuw             
    ,enumlr_w              
    ,enumsc_w              
    ,enumlr_d              
    ,enumsc_d              
    ,enumecall             
    ,enumebreak            
    ,enumuret              
    ,enummret              
    ,enumdret              
    ,enumsfence_vma        
    ,enumwfi               
    ,enumcsrrw             
    ,enumcsrrs             
    ,enumcsrrc             
    ,enumcsrrwi            
    ,enumcsrrsi            
    ,enumcsrrci            
    ,enumcustom0           
    ,enumcustom0_rs1       
    ,enumcustom0_rs1_rs2   
    ,enumcustom0_rd        
    ,enumcustom0_rd_rs1    
    ,enumcustom0_rd_rs1_rs2
    ,enumcustom1           
    ,enumcustom1_rs1       
    ,enumcustom1_rs1_rs2   
    ,enumcustom1_rd        
    ,enumcustom1_rd_rs1    
    ,enumcustom1_rd_rs1_rs2
    ,enumcustom2           
    ,enumcustom2_rs1       
    ,enumcustom2_rs1_rs2   
    ,enumcustom2_rd        
    ,enumcustom2_rd_rs1    
    ,enumcustom2_rd_rs1_rs2
    ,enumcustom3           
    ,enumcustom3_rs1       
    ,enumcustom3_rs1_rs2   
    ,enumcustom3_rd        
    ,enumcustom3_rd_rs1    
    ,enumcustom3_rd_rs1_rs2
    ,enumslli_rv32         
    ,enumsrli_rv32         
    ,enumsrai_rv32         
    ,enumrdcycle           
    ,enumrdtime            
    ,enumrdinstret         
    ,enumrdcycleh          
    ,enumrdtimeh           
    ,enumrdinstreth        

};

int findenum(string const& opcode){

if( opcode == "beq"                ) return enumbeq               ;
if( opcode == "bne"                ) return enumbne               ;
if( opcode == "blt"                ) return enumblt               ;
if( opcode == "bge"                ) return enumbge               ;
if( opcode == "bltu"               ) return enumbltu              ;
if( opcode == "bgeu"               ) return enumbgeu              ;
if( opcode == "jalr"               ) return enumjalr              ;
if( opcode == "jal"                ) return enumjal               ;
if( opcode == "lui"                ) return enumlui               ;
if( opcode == "auipc"              ) return enumauipc             ;
if( opcode == "addi"               ) return enumaddi              ;
if( opcode == "slli"               ) return enumslli              ;
if( opcode == "slti"               ) return enumslti              ;
if( opcode == "sltiu"              ) return enumsltiu             ;
if( opcode == "xori"               ) return enumxori              ;
if( opcode == "srli"               ) return enumsrli              ;
if( opcode == "srai"               ) return enumsrai              ;
if( opcode == "ori"                ) return enumori               ;
if( opcode == "andi"               ) return enumandi              ;
if( opcode == "add"                ) return enumadd               ;
if( opcode == "sub"                ) return enumsub               ;
if( opcode == "sll"                ) return enumsll               ;
if( opcode == "slt"                ) return enumslt               ;
if( opcode == "sltu"               ) return enumsltu              ;
if( opcode == "xor"                ) return enumxor_              ;
if( opcode == "srl"                ) return enumsrl               ;
if( opcode == "sra"                ) return enumsra               ;
if( opcode == "or"                 ) return enumor_               ;
if( opcode == "and"                ) return enumand_              ;
if( opcode == "addiw"              ) return enumaddiw             ;
if( opcode == "slliw"              ) return enumslliw             ;
if( opcode == "srliw"              ) return enumsrliw             ;
if( opcode == "sraiw"              ) return enumsraiw             ;
if( opcode == "addw"               ) return enumaddw              ;
if( opcode == "subw"               ) return enumsubw              ;
if( opcode == "sllw"               ) return enumsllw              ;
if( opcode == "srlw"               ) return enumsrlw              ;
if( opcode == "sraw"               ) return enumsraw              ;
if( opcode == "lb"                 ) return enumlb                ;
if( opcode == "lh"                 ) return enumlh                ;
if( opcode == "lw"                 ) return enumlw                ;
if( opcode == "ld"                 ) return enumld                ;
if( opcode == "lbu"                ) return enumlbu               ;
if( opcode == "lhu"                ) return enumlhu               ;
if( opcode == "lwu"                ) return enumlwu               ;
if( opcode == "sb"                 ) return enumsb                ;
if( opcode == "sh"                 ) return enumsh                ;
if( opcode == "sw"                 ) return enumsw                ;
if( opcode == "sd"                 ) return enumsd                ;
if( opcode == "fence"              ) return enumfence             ;
if( opcode == "fence_i"            ) return enumfence_i           ;
if( opcode == "mul"                ) return enummul               ;
if( opcode == "mulh"               ) return enummulh              ;
if( opcode == "mulhsu"             ) return enummulhsu            ;
if( opcode == "mulhu"              ) return enummulhu             ;
if( opcode == "div"                ) return enumdiv               ;
if( opcode == "divu"               ) return enumdivu              ;
if( opcode == "rem"                ) return enumrem               ;
if( opcode == "remu"               ) return enumremu              ;
if( opcode == "mulw"               ) return enummulw              ;
if( opcode == "divw"               ) return enumdivw              ;
if( opcode == "divuw"              ) return enumdivuw             ;
if( opcode == "remw"               ) return enumremw              ;
if( opcode == "remuw"              ) return enumremuw             ;
if( opcode == "lr_w"               ) return enumlr_w              ;
if( opcode == "sc_w"               ) return enumsc_w              ;
if( opcode == "lr_d"               ) return enumlr_d              ;
if( opcode == "sc_d"               ) return enumsc_d              ;
if( opcode == "ecall"              ) return enumecall             ;
if( opcode == "ebreak"             ) return enumebreak            ;
if( opcode == "uret"               ) return enumuret              ;
if( opcode == "mret"               ) return enummret              ;
if( opcode == "dret"               ) return enumdret              ;
if( opcode == "sfence_vma"         ) return enumsfence_vma        ;
if( opcode == "wfi"                ) return enumwfi               ;
if( opcode == "csrrw"              ) return enumcsrrw             ;
if( opcode == "csrrs"              ) return enumcsrrs             ;
if( opcode == "csrrc"              ) return enumcsrrc             ;
if( opcode == "csrrwi"             ) return enumcsrrwi            ;
if( opcode == "csrrsi"             ) return enumcsrrsi            ;
if( opcode == "csrrci"             ) return enumcsrrci            ;
if( opcode == "custom0"            ) return enumcustom0           ;
if( opcode == "custom0_rs1"        ) return enumcustom0_rs1       ;
if( opcode == "custom0_rs1_rs2"    ) return enumcustom0_rs1_rs2   ;
if( opcode == "custom0_rd"         ) return enumcustom0_rd        ;
if( opcode == "custom0_rd_rs1"     ) return enumcustom0_rd_rs1    ;
if( opcode == "custom0_rd_rs1_rs2" ) return enumcustom0_rd_rs1_rs2;
if( opcode == "custom1"            ) return enumcustom1           ;
if( opcode == "custom1_rs1"        ) return enumcustom1_rs1       ;
if( opcode == "custom1_rs1_rs2"    ) return enumcustom1_rs1_rs2   ;
if( opcode == "custom1_rd"         ) return enumcustom1_rd        ;
if( opcode == "custom1_rd_rs1"     ) return enumcustom1_rd_rs1    ;
if( opcode == "custom1_rd_rs1_rs2" ) return enumcustom1_rd_rs1_rs2;
if( opcode == "custom2"            ) return enumcustom2           ;
if( opcode == "custom2_rs1"        ) return enumcustom2_rs1       ;
if( opcode == "custom2_rs1_rs2"    ) return enumcustom2_rs1_rs2   ;
if( opcode == "custom2_rd"         ) return enumcustom2_rd        ;
if( opcode == "custom2_rd_rs1"     ) return enumcustom2_rd_rs1    ;
if( opcode == "custom2_rd_rs1_rs2" ) return enumcustom2_rd_rs1_rs2;
if( opcode == "custom3"            ) return enumcustom3           ;
if( opcode == "custom3_rs1"        ) return enumcustom3_rs1       ;
if( opcode == "custom3_rs1_rs2"    ) return enumcustom3_rs1_rs2   ;
if( opcode == "custom3_rd"         ) return enumcustom3_rd        ;
if( opcode == "custom3_rd_rs1"     ) return enumcustom3_rd_rs1    ;
if( opcode == "custom3_rd_rs1_rs2" ) return enumcustom3_rd_rs1_rs2;
if( opcode == "slli_rv32"          ) return enumslli_rv32         ;
if( opcode == "srli_rv32"          ) return enumsrli_rv32         ;
if( opcode == "srai_rv32"          ) return enumsrai_rv32         ;
if( opcode == "rdcycle"            ) return enumrdcycle           ;
if( opcode == "rdtime"             ) return enumrdtime            ;
if( opcode == "rdinstret"          ) return enumrdinstret         ;
if( opcode == "rdcycleh"           ) return enumrdcycleh          ;
if( opcode == "rdtimeh"            ) return enumrdtimeh           ;
if( opcode == "rdinstreth"         ) return enumrdinstreth        ;

return 0;

}
*/
int main(int argc, char *argv[]){

int total = 0;

int beq                = 0;
int bne                = 0;
int blt                = 0;
int bge                = 0;
int bltu               = 0;
int bgeu               = 0;
int jalr               = 0;
int jal                = 0;
int lui                = 0;
int auipc              = 0;
int addi               = 0;
int slli               = 0;
int slti               = 0;
int sltiu              = 0;
int xori               = 0;
int srli               = 0;
int srai               = 0;
int ori                = 0;
int andi               = 0;
int add                = 0;
int sub                = 0;
int sll                = 0;
int slt                = 0;
int sltu               = 0;
int xor_                = 0;
int srl                = 0;
int sra                = 0;
int or_                 = 0;
int and_                = 0;
int addiw              = 0;
int slliw              = 0;
int srliw              = 0;
int sraiw              = 0;
int addw               = 0;
int subw               = 0;
int sllw               = 0;
int srlw               = 0;
int sraw               = 0;
int lb                 = 0;
int lh                 = 0;
int lw                 = 0;
int ld                 = 0;
int lbu                = 0;
int lhu                = 0;
int lwu                = 0;
int sb                 = 0;
int sh                 = 0;
int sw                 = 0;
int sd                 = 0;
int fence              = 0;
int fence_i            = 0;
int mul                = 0;
int mulh               = 0;
int mulhsu             = 0;
int mulhu              = 0;
int div                = 0;
int divu               = 0;
int rem                = 0;
int remu               = 0;
int mulw               = 0;
int divw               = 0;
int divuw              = 0;
int remw               = 0;
int remuw              = 0;
int lr_w               = 0;
int sc_w               = 0;
int lr_d               = 0;
int sc_d               = 0;
int ecall              = 0;
int ebreak             = 0;
int uret               = 0;
int mret               = 0;
int dret               = 0;
int sfence_vma         = 0;
int wfi                = 0;
int csrrw              = 0;
int csrrs              = 0;
int csrrc              = 0;
int csrrwi             = 0;
int csrrsi             = 0;
int csrrci             = 0;
int custom0            = 0;
int custom0_rs1        = 0;
int custom0_rs1_rs2    = 0;
int custom0_rd         = 0;
int custom0_rd_rs1     = 0;
int custom0_rd_rs1_rs2 = 0;
int custom1            = 0;
int custom1_rs1        = 0;
int custom1_rs1_rs2    = 0;
int custom1_rd         = 0;
int custom1_rd_rs1     = 0;
int custom1_rd_rs1_rs2 = 0;
int custom2            = 0;
int custom2_rs1        = 0;
int custom2_rs1_rs2    = 0;
int custom2_rd         = 0;
int custom2_rd_rs1     = 0;
int custom2_rd_rs1_rs2 = 0;
int custom3            = 0;
int custom3_rs1        = 0;
int custom3_rs1_rs2    = 0;
int custom3_rd         = 0;
int custom3_rd_rs1     = 0;
int custom3_rd_rs1_rs2 = 0;
int slli_rv32          = 0;
int srli_rv32          = 0;
int srai_rv32          = 0;
int rdcycle            = 0;
int rdtime             = 0;
int rdinstret          = 0;
int rdcycleh           = 0;
int rdtimeh            = 0;
int rdinstreth         = 0;


    string opcode = "";

    string filename = string(argv[1]);
    ifstream read(filename);

    cout<<endl;
    //cout<<endl<<filename<<endl;
//read >> std::noskipws;
    char character;
if (read.is_open()){
    while(read >> std::noskipws >> character){
        
        if(!isspace(character) && character != '\n')
        opcode += string(1,character);
        else {
            //cout<<opcode<<endl;
            if( opcode == "beq"                ){ ++beq               ; ++total; }
            if( opcode == "bne"                ){ ++bne               ; ++total; }
            if( opcode == "blt"                ){ ++blt               ; ++total; }
            if( opcode == "bge"                ){ ++bge               ; ++total; }
            if( opcode == "bltu"               ){ ++bltu              ; ++total; }
            if( opcode == "bgeu"               ){ ++bgeu              ; ++total; }
            if( opcode == "jalr"               ){ ++jalr              ; ++total; }
            if( opcode == "jal"                ){ ++jal               ; ++total; }
            if( opcode == "lui"                ){ ++lui               ; ++total; }
            if( opcode == "auipc"              ){ ++auipc             ; ++total; }
            if( opcode == "addi"               ){ ++addi              ; ++total; }
            if( opcode == "slli"               ){ ++slli              ; ++total; }
            if( opcode == "slti"               ){ ++slti              ; ++total; }
            if( opcode == "sltiu"              ){ ++sltiu             ; ++total; }
            if( opcode == "xori"               ){ ++xori              ; ++total; }
            if( opcode == "srli"               ){ ++srli              ; ++total; }
            if( opcode == "srai"               ){ ++srai              ; ++total; }
            if( opcode == "ori"                ){ ++ori               ; ++total; }
            if( opcode == "andi"               ){ ++andi              ; ++total; }
            if( opcode == "add"                ){ ++add               ; ++total; }
            if( opcode == "sub"                ){ ++sub               ; ++total; }
            if( opcode == "sll"                ){ ++sll               ; ++total; }
            if( opcode == "slt"                ){ ++slt               ; ++total; }
            if( opcode == "sltu"               ){ ++sltu              ; ++total; }
            if( opcode == "xor"                ){ ++xor_               ; ++total; }
            if( opcode == "srl"                ){ ++srl               ; ++total; }
            if( opcode == "sra"                ){ ++sra               ; ++total; }
            if( opcode == "or"                 ){ ++or_                ; ++total; }
            if( opcode == "and"                ){ ++and_               ; ++total; }
            if( opcode == "addiw"              ){ ++addiw             ; ++total; }
            if( opcode == "slliw"              ){ ++slliw             ; ++total; }
            if( opcode == "srliw"              ){ ++srliw             ; ++total; }
            if( opcode == "sraiw"              ){ ++sraiw             ; ++total; }
            if( opcode == "addw"               ){ ++addw              ; ++total; }
            if( opcode == "subw"               ){ ++subw              ; ++total; }
            if( opcode == "sllw"               ){ ++sllw              ; ++total; }
            if( opcode == "srlw"               ){ ++srlw              ; ++total; }
            if( opcode == "sraw"               ){ ++sraw              ; ++total; }
            if( opcode == "lb"                 ){ ++lb                ; ++total; }
            if( opcode == "lh"                 ){ ++lh                ; ++total; }
            if( opcode == "lw"                 ){ ++lw                ; ++total; }
            if( opcode == "ld"                 ){ ++ld                ; ++total; }
            if( opcode == "lbu"                ){ ++lbu               ; ++total; }
            if( opcode == "lhu"                ){ ++lhu               ; ++total; }
            if( opcode == "lwu"                ){ ++lwu               ; ++total; }
            if( opcode == "sb"                 ){ ++sb                ; ++total; }
            if( opcode == "sh"                 ){ ++sh                ; ++total; }
            if( opcode == "sw"                 ){ ++sw                ; ++total; }
            if( opcode == "sd"                 ){ ++sd                ; ++total; }
            if( opcode == "fence"              ){ ++fence             ; ++total; }
            if( opcode == "fence_i"            ){ ++fence_i           ; ++total; }
            if( opcode == "mul"                ){ ++mul               ; ++total; }
            if( opcode == "mulh"               ){ ++mulh              ; ++total; }
            if( opcode == "mulhsu"             ){ ++mulhsu            ; ++total; }
            if( opcode == "mulhu"              ){ ++mulhu             ; ++total; }
            if( opcode == "div"                ){ ++div               ; ++total; }
            if( opcode == "divu"               ){ ++divu              ; ++total; }
            if( opcode == "rem"                ){ ++rem               ; ++total; }
            if( opcode == "remu"               ){ ++remu              ; ++total; }
            if( opcode == "mulw"               ){ ++mulw              ; ++total; }
            if( opcode == "divw"               ){ ++divw              ; ++total; }
            if( opcode == "divuw"              ){ ++divuw             ; ++total; }
            if( opcode == "remw"               ){ ++remw              ; ++total; }
            if( opcode == "remuw"              ){ ++remuw             ; ++total; }
            if( opcode == "lr_w"               ){ ++lr_w              ; ++total; }
            if( opcode == "sc_w"               ){ ++sc_w              ; ++total; }
            if( opcode == "lr_d"               ){ ++lr_d              ; ++total; }
            if( opcode == "sc_d"               ){ ++sc_d              ; ++total; }
            if( opcode == "ecall"              ){ ++ecall             ; ++total; }
            if( opcode == "ebreak"             ){ ++ebreak            ; ++total; }
            if( opcode == "uret"               ){ ++uret              ; ++total; }
            if( opcode == "mret"               ){ ++mret              ; ++total; }
            if( opcode == "dret"               ){ ++dret              ; ++total; }
            if( opcode == "sfence_vma"         ){ ++sfence_vma        ; ++total; }
            if( opcode == "wfi"                ){ ++wfi               ; ++total; }
            if( opcode == "csrrw"              ){ ++csrrw             ; ++total; }
            if( opcode == "csrrs"              ){ ++csrrs             ; ++total; }
            if( opcode == "csrrc"              ){ ++csrrc             ; ++total; }
            if( opcode == "csrrwi"             ){ ++csrrwi            ; ++total; }
            if( opcode == "csrrsi"             ){ ++csrrsi            ; ++total; }
            if( opcode == "csrrci"             ){ ++csrrci            ; ++total; }
            if( opcode == "custom0"            ){ ++custom0           ; ++total; }
            if( opcode == "custom0_rs1"        ){ ++custom0_rs1       ; ++total; }
            if( opcode == "custom0_rs1_rs2"    ){ ++custom0_rs1_rs2   ; ++total; }
            if( opcode == "custom0_rd"         ){ ++custom0_rd        ; ++total; }
            if( opcode == "custom0_rd_rs1"     ){ ++custom0_rd_rs1    ; ++total; }
            if( opcode == "custom0_rd_rs1_rs2" ){ ++custom0_rd_rs1_rs2; ++total; }
            if( opcode == "custom1"            ){ ++custom1           ; ++total; }
            if( opcode == "custom1_rs1"        ){ ++custom1_rs1       ; ++total; }
            if( opcode == "custom1_rs1_rs2"    ){ ++custom1_rs1_rs2   ; ++total; }
            if( opcode == "custom1_rd"         ){ ++custom1_rd        ; ++total; }
            if( opcode == "custom1_rd_rs1"     ){ ++custom1_rd_rs1    ; ++total; }
            if( opcode == "custom1_rd_rs1_rs2" ){ ++custom1_rd_rs1_rs2; ++total; }
            if( opcode == "custom2"            ){ ++custom2           ; ++total; }
            if( opcode == "custom2_rs1"        ){ ++custom2_rs1       ; ++total; }
            if( opcode == "custom2_rs1_rs2"    ){ ++custom2_rs1_rs2   ; ++total; }
            if( opcode == "custom2_rd"         ){ ++custom2_rd        ; ++total; }
            if( opcode == "custom2_rd_rs1"     ){ ++custom2_rd_rs1    ; ++total; }
            if( opcode == "custom2_rd_rs1_rs2" ){ ++custom2_rd_rs1_rs2; ++total; }
            if( opcode == "custom3"            ){ ++custom3           ; ++total; }
            if( opcode == "custom3_rs1"        ){ ++custom3_rs1       ; ++total; }
            if( opcode == "custom3_rs1_rs2"    ){ ++custom3_rs1_rs2   ; ++total; }
            if( opcode == "custom3_rd"         ){ ++custom3_rd        ; ++total; }
            if( opcode == "custom3_rd_rs1"     ){ ++custom3_rd_rs1    ; ++total; }
            if( opcode == "custom3_rd_rs1_rs2" ){ ++custom3_rd_rs1_rs2; ++total; }
            if( opcode == "slli_rv32"          ){ ++slli_rv32         ; ++total; }
            if( opcode == "srli_rv32"          ){ ++srli_rv32         ; ++total; }
            if( opcode == "srai_rv32"          ){ ++srai_rv32         ; ++total; }
            if( opcode == "rdcycle"            ){ ++rdcycle           ; ++total; }
            if( opcode == "rdtime"             ){ ++rdtime            ; ++total; }
            if( opcode == "rdinstret"          ){ ++rdinstret         ; ++total; }
            if( opcode == "rdcycleh"           ){ ++rdcycleh          ; ++total; }
            if( opcode == "rdtimeh"            ){ ++rdtimeh           ; ++total; }
            if( opcode == "rdinstreth"         ){ ++rdinstreth        ; ++total; }
            opcode = "";
        }

    }
}

read.close();

cout.precision(3);

if(beq                != 0) cout<<"beq               \t"<<beq               <<"\t   %"<<100 * beq               /(double)total<<endl;
if(bne                != 0) cout<<"bne               \t"<<bne               <<"\t   %"<<100 * bne               /(double)total<<endl;
if(blt                != 0) cout<<"blt               \t"<<blt               <<"\t   %"<<100 * blt               /(double)total<<endl;
if(bge                != 0) cout<<"bge               \t"<<bge               <<"\t   %"<<100 * bge               /(double)total<<endl;
if(bltu               != 0) cout<<"bltu              \t"<<bltu              <<"\t   %"<<100 * bltu              /(double)total<<endl;
if(bgeu               != 0) cout<<"bgeu              \t"<<bgeu              <<"\t   %"<<100 * bgeu              /(double)total<<endl;
if(jalr               != 0) cout<<"jalr              \t"<<jalr              <<"\t   %"<<100 * jalr              /(double)total<<endl;
if(jal                != 0) cout<<"jal               \t"<<jal               <<"\t   %"<<100 * jal               /(double)total<<endl;
if(lui                != 0) cout<<"lui               \t"<<lui               <<"\t   %"<<100 * lui               /(double)total<<endl;
if(auipc              != 0) cout<<"auipc             \t"<<auipc             <<"\t   %"<<100 * auipc             /(double)total<<endl;
if(addi               != 0) cout<<"addi              \t"<<addi              <<"\t   %"<<100 * addi              /(double)total<<endl;
if(slli               != 0) cout<<"slli              \t"<<slli              <<"\t   %"<<100 * slli              /(double)total<<endl;
if(slti               != 0) cout<<"slti              \t"<<slti              <<"\t   %"<<100 * slti              /(double)total<<endl;
if(sltiu              != 0) cout<<"sltiu             \t"<<sltiu             <<"\t   %"<<100 * sltiu             /(double)total<<endl;
if(xori               != 0) cout<<"xori              \t"<<xori              <<"\t   %"<<100 * xori              /(double)total<<endl;
if(srli               != 0) cout<<"srli              \t"<<srli              <<"\t   %"<<100 * srli              /(double)total<<endl;
if(srai               != 0) cout<<"srai              \t"<<srai              <<"\t   %"<<100 * srai              /(double)total<<endl;
if(ori                != 0) cout<<"ori               \t"<<ori               <<"\t   %"<<100 * ori               /(double)total<<endl;
if(andi               != 0) cout<<"andi              \t"<<andi              <<"\t   %"<<100 * andi              /(double)total<<endl;
if(add                != 0) cout<<"add               \t"<<add               <<"\t   %"<<100 * add               /(double)total<<endl;
if(sub                != 0) cout<<"sub               \t"<<sub               <<"\t   %"<<100 * sub               /(double)total<<endl;
if(sll                != 0) cout<<"sll               \t"<<sll               <<"\t   %"<<100 * sll               /(double)total<<endl;
if(slt                != 0) cout<<"slt               \t"<<slt               <<"\t   %"<<100 * slt               /(double)total<<endl;
if(sltu               != 0) cout<<"sltu              \t"<<sltu              <<"\t   %"<<100 * sltu              /(double)total<<endl;
if(xor_                != 0) cout<<"xor               \t"<<xor_               <<"\t   %"<<100 * xor_               /(double)total<<endl;
if(srl                != 0) cout<<"srl               \t"<<srl               <<"\t   %"<<100 * srl               /(double)total<<endl;
if(sra                != 0) cout<<"sra               \t"<<sra               <<"\t   %"<<100 * sra               /(double)total<<endl;
if(or_                 != 0) cout<<"or                \t"<<or_                <<"\t   %"<<100 * or_                /(double)total<<endl;
if(and_                != 0) cout<<"and               \t"<<and_               <<"\t   %"<<100 * and_               /(double)total<<endl;
if(addiw              != 0) cout<<"addiw             \t"<<addiw             <<"\t   %"<<100 * addiw             /(double)total<<endl;
if(slliw              != 0) cout<<"slliw             \t"<<slliw             <<"\t   %"<<100 * slliw             /(double)total<<endl;
if(srliw              != 0) cout<<"srliw             \t"<<srliw             <<"\t   %"<<100 * srliw             /(double)total<<endl;
if(sraiw              != 0) cout<<"sraiw             \t"<<sraiw             <<"\t   %"<<100 * sraiw             /(double)total<<endl;
if(addw               != 0) cout<<"addw              \t"<<addw              <<"\t   %"<<100 * addw              /(double)total<<endl;
if(subw               != 0) cout<<"subw              \t"<<subw              <<"\t   %"<<100 * subw              /(double)total<<endl;
if(sllw               != 0) cout<<"sllw              \t"<<sllw              <<"\t   %"<<100 * sllw              /(double)total<<endl;
if(srlw               != 0) cout<<"srlw              \t"<<srlw              <<"\t   %"<<100 * srlw              /(double)total<<endl;
if(sraw               != 0) cout<<"sraw              \t"<<sraw              <<"\t   %"<<100 * sraw              /(double)total<<endl;
if(lb                 != 0) cout<<"lb                \t"<<lb                <<"\t   %"<<100 * lb                /(double)total<<endl;
if(lh                 != 0) cout<<"lh                \t"<<lh                <<"\t   %"<<100 * lh                /(double)total<<endl;
if(lw                 != 0) cout<<"lw                \t"<<lw                <<"\t   %"<<100 * lw                /(double)total<<endl;
if(ld                 != 0) cout<<"ld                \t"<<ld                <<"\t   %"<<100 * ld                /(double)total<<endl;
if(lbu                != 0) cout<<"lbu               \t"<<lbu               <<"\t   %"<<100 * lbu               /(double)total<<endl;
if(lhu                != 0) cout<<"lhu               \t"<<lhu               <<"\t   %"<<100 * lhu               /(double)total<<endl;
if(lwu                != 0) cout<<"lwu               \t"<<lwu               <<"\t   %"<<100 * lwu               /(double)total<<endl;
if(sb                 != 0) cout<<"sb                \t"<<sb                <<"\t   %"<<100 * sb                /(double)total<<endl;
if(sh                 != 0) cout<<"sh                \t"<<sh                <<"\t   %"<<100 * sh                /(double)total<<endl;
if(sw                 != 0) cout<<"sw                \t"<<sw                <<"\t   %"<<100 * sw                /(double)total<<endl;
if(sd                 != 0) cout<<"sd                \t"<<sd                <<"\t   %"<<100 * sd                /(double)total<<endl;
if(fence              != 0) cout<<"fence             \t"<<fence             <<"\t   %"<<100 * fence             /(double)total<<endl;
if(fence_i            != 0) cout<<"fence_i           \t"<<fence_i           <<"\t   %"<<100 * fence_i           /(double)total<<endl;
if(mul                != 0) cout<<"mul               \t"<<mul               <<"\t   %"<<100 * mul               /(double)total<<endl;
if(mulh               != 0) cout<<"mulh              \t"<<mulh              <<"\t   %"<<100 * mulh              /(double)total<<endl;
if(mulhsu             != 0) cout<<"mulhsu            \t"<<mulhsu            <<"\t   %"<<100 * mulhsu            /(double)total<<endl;
if(mulhu              != 0) cout<<"mulhu             \t"<<mulhu             <<"\t   %"<<100 * mulhu             /(double)total<<endl;
if(div                != 0) cout<<"div               \t"<<div               <<"\t   %"<<100 * div               /(double)total<<endl;
if(divu               != 0) cout<<"divu              \t"<<divu              <<"\t   %"<<100 * divu              /(double)total<<endl;
if(rem                != 0) cout<<"rem               \t"<<rem               <<"\t   %"<<100 * rem               /(double)total<<endl;
if(remu               != 0) cout<<"remu              \t"<<remu              <<"\t   %"<<100 * remu              /(double)total<<endl;
if(mulw               != 0) cout<<"mulw              \t"<<mulw              <<"\t   %"<<100 * mulw              /(double)total<<endl;
if(divw               != 0) cout<<"divw              \t"<<divw              <<"\t   %"<<100 * divw              /(double)total<<endl;
if(divuw              != 0) cout<<"divuw             \t"<<divuw             <<"\t   %"<<100 * divuw             /(double)total<<endl;
if(remw               != 0) cout<<"remw              \t"<<remw              <<"\t   %"<<100 * remw              /(double)total<<endl;
if(remuw              != 0) cout<<"remuw             \t"<<remuw             <<"\t   %"<<100 * remuw             /(double)total<<endl;
if(lr_w               != 0) cout<<"lr_w              \t"<<lr_w              <<"\t   %"<<100 * lr_w              /(double)total<<endl;
if(sc_w               != 0) cout<<"sc_w              \t"<<sc_w              <<"\t   %"<<100 * sc_w              /(double)total<<endl;
if(lr_d               != 0) cout<<"lr_d              \t"<<lr_d              <<"\t   %"<<100 * lr_d              /(double)total<<endl;
if(sc_d               != 0) cout<<"sc_d              \t"<<sc_d              <<"\t   %"<<100 * sc_d              /(double)total<<endl;
if(ecall              != 0) cout<<"ecall             \t"<<ecall             <<"\t   %"<<100 * ecall             /(double)total<<endl;
if(ebreak             != 0) cout<<"ebreak            \t"<<ebreak            <<"\t   %"<<100 * ebreak            /(double)total<<endl;
if(uret               != 0) cout<<"uret              \t"<<uret              <<"\t   %"<<100 * uret              /(double)total<<endl;
if(mret               != 0) cout<<"mret              \t"<<mret              <<"\t   %"<<100 * mret              /(double)total<<endl;
if(dret               != 0) cout<<"dret              \t"<<dret              <<"\t   %"<<100 * dret              /(double)total<<endl;
if(sfence_vma         != 0) cout<<"sfence_vma        \t"<<sfence_vma        <<"\t   %"<<100 * sfence_vma        /(double)total<<endl;
if(wfi                != 0) cout<<"wfi               \t"<<wfi               <<"\t   %"<<100 * wfi               /(double)total<<endl;
if(csrrw              != 0) cout<<"csrrw             \t"<<csrrw             <<"\t   %"<<100 * csrrw             /(double)total<<endl;
if(csrrs              != 0) cout<<"csrrs             \t"<<csrrs             <<"\t   %"<<100 * csrrs             /(double)total<<endl;
if(csrrc              != 0) cout<<"csrrc             \t"<<csrrc             <<"\t   %"<<100 * csrrc             /(double)total<<endl;
if(csrrwi             != 0) cout<<"csrrwi            \t"<<csrrwi            <<"\t   %"<<100 * csrrwi            /(double)total<<endl;
if(csrrsi             != 0) cout<<"csrrsi            \t"<<csrrsi            <<"\t   %"<<100 * csrrsi            /(double)total<<endl;
if(csrrci             != 0) cout<<"csrrci            \t"<<csrrci            <<"\t   %"<<100 * csrrci            /(double)total<<endl;
if(custom0            != 0) cout<<"custom0           \t"<<custom0           <<"\t   %"<<100 * custom0           /(double)total<<endl;
if(custom0_rs1        != 0) cout<<"custom0_rs1       \t"<<custom0_rs1       <<"\t   %"<<100 * custom0_rs1       /(double)total<<endl;
if(custom0_rs1_rs2    != 0) cout<<"custom0_rs1_rs2   \t"<<custom0_rs1_rs2   <<"\t   %"<<100 * custom0_rs1_rs2   /(double)total<<endl;
if(custom0_rd         != 0) cout<<"custom0_rd        \t"<<custom0_rd        <<"\t   %"<<100 * custom0_rd        /(double)total<<endl;
if(custom0_rd_rs1     != 0) cout<<"custom0_rd_rs1    \t"<<custom0_rd_rs1    <<"\t   %"<<100 * custom0_rd_rs1    /(double)total<<endl;
if(custom0_rd_rs1_rs2 != 0) cout<<"custom0_rd_rs1_rs2\t"<<custom0_rd_rs1_rs2<<"\t   %"<<100 * custom0_rd_rs1_rs2/(double)total<<endl;
if(custom1            != 0) cout<<"custom1           \t"<<custom1           <<"\t   %"<<100 * custom1           /(double)total<<endl;
if(custom1_rs1        != 0) cout<<"custom1_rs1       \t"<<custom1_rs1       <<"\t   %"<<100 * custom1_rs1       /(double)total<<endl;
if(custom1_rs1_rs2    != 0) cout<<"custom1_rs1_rs2   \t"<<custom1_rs1_rs2   <<"\t   %"<<100 * custom1_rs1_rs2   /(double)total<<endl;
if(custom1_rd         != 0) cout<<"custom1_rd        \t"<<custom1_rd        <<"\t   %"<<100 * custom1_rd        /(double)total<<endl;
if(custom1_rd_rs1     != 0) cout<<"custom1_rd_rs1    \t"<<custom1_rd_rs1    <<"\t   %"<<100 * custom1_rd_rs1    /(double)total<<endl;
if(custom1_rd_rs1_rs2 != 0) cout<<"custom1_rd_rs1_rs2\t"<<custom1_rd_rs1_rs2<<"\t   %"<<100 * custom1_rd_rs1_rs2/(double)total<<endl;
if(custom2            != 0) cout<<"custom2           \t"<<custom2           <<"\t   %"<<100 * custom2           /(double)total<<endl;
if(custom2_rs1        != 0) cout<<"custom2_rs1       \t"<<custom2_rs1       <<"\t   %"<<100 * custom2_rs1       /(double)total<<endl;
if(custom2_rs1_rs2    != 0) cout<<"custom2_rs1_rs2   \t"<<custom2_rs1_rs2   <<"\t   %"<<100 * custom2_rs1_rs2   /(double)total<<endl;
if(custom2_rd         != 0) cout<<"custom2_rd        \t"<<custom2_rd        <<"\t   %"<<100 * custom2_rd        /(double)total<<endl;
if(custom2_rd_rs1     != 0) cout<<"custom2_rd_rs1    \t"<<custom2_rd_rs1    <<"\t   %"<<100 * custom2_rd_rs1    /(double)total<<endl;
if(custom2_rd_rs1_rs2 != 0) cout<<"custom2_rd_rs1_rs2\t"<<custom2_rd_rs1_rs2<<"\t   %"<<100 * custom2_rd_rs1_rs2/(double)total<<endl;
if(custom3            != 0) cout<<"custom3           \t"<<custom3           <<"\t   %"<<100 * custom3           /(double)total<<endl;
if(custom3_rs1        != 0) cout<<"custom3_rs1       \t"<<custom3_rs1       <<"\t   %"<<100 * custom3_rs1       /(double)total<<endl;
if(custom3_rs1_rs2    != 0) cout<<"custom3_rs1_rs2   \t"<<custom3_rs1_rs2   <<"\t   %"<<100 * custom3_rs1_rs2   /(double)total<<endl;
if(custom3_rd         != 0) cout<<"custom3_rd        \t"<<custom3_rd        <<"\t   %"<<100 * custom3_rd        /(double)total<<endl;
if(custom3_rd_rs1     != 0) cout<<"custom3_rd_rs1    \t"<<custom3_rd_rs1    <<"\t   %"<<100 * custom3_rd_rs1    /(double)total<<endl;
if(custom3_rd_rs1_rs2 != 0) cout<<"custom3_rd_rs1_rs2\t"<<custom3_rd_rs1_rs2<<"\t   %"<<100 * custom3_rd_rs1_rs2/(double)total<<endl;
if(slli_rv32          != 0) cout<<"slli_rv32         \t"<<slli_rv32         <<"\t   %"<<100 * slli_rv32         /(double)total<<endl;
if(srli_rv32          != 0) cout<<"srli_rv32         \t"<<srli_rv32         <<"\t   %"<<100 * srli_rv32         /(double)total<<endl;
if(srai_rv32          != 0) cout<<"srai_rv32         \t"<<srai_rv32         <<"\t   %"<<100 * srai_rv32         /(double)total<<endl;
if(rdcycle            != 0) cout<<"rdcycle           \t"<<rdcycle           <<"\t   %"<<100 * rdcycle           /(double)total<<endl;
if(rdtime             != 0) cout<<"rdtime            \t"<<rdtime            <<"\t   %"<<100 * rdtime            /(double)total<<endl;
if(rdinstret          != 0) cout<<"rdinstret         \t"<<rdinstret         <<"\t   %"<<100 * rdinstret         /(double)total<<endl;
if(rdcycleh           != 0) cout<<"rdcycleh          \t"<<rdcycleh          <<"\t   %"<<100 * rdcycleh          /(double)total<<endl;
if(rdtimeh            != 0) cout<<"rdtimeh           \t"<<rdtimeh           <<"\t   %"<<100 * rdtimeh           /(double)total<<endl;
if(rdinstreth         != 0) cout<<"rdinstreth        \t"<<rdinstreth        <<"\t   %"<<100 * rdinstreth        /(double)total<<endl;

cout<<endl;

    return 0;
}

/*
if(beq                != 0) cout<<"beq               :"<<endl;
if(bne                != 0) cout<<"bne               :"<<endl;
if(blt                != 0) cout<<"blt               :"<<endl;
if(bge                != 0) cout<<"bge               :"<<endl;
if(bltu               != 0) cout<<"bltu              :"<<endl;
if(bgeu               != 0) cout<<"bgeu              :"<<endl;
if(jalr               != 0) cout<<"jalr              :"<<endl;
if(jal                != 0) cout<<"jal               :"<<endl;
if(lui                != 0) cout<<"lui               :"<<endl;
if(auipc              != 0) cout<<"auipc             :"<<endl;
if(addi               != 0) cout<<"addi              :"<<endl;
if(slli               != 0) cout<<"slli              :"<<endl;
if(slti               != 0) cout<<"slti              :"<<endl;
if(sltiu              != 0) cout<<"sltiu             :"<<endl;
if(xori               != 0) cout<<"xori              :"<<endl;
if(srli               != 0) cout<<"srli              :"<<endl;
if(srai               != 0) cout<<"srai              :"<<endl;
if(ori                != 0) cout<<"ori               :"<<endl;
if(andi               != 0) cout<<"andi              :"<<endl;
if(add                != 0) cout<<"add               :"<<endl;
if(sub                != 0) cout<<"sub               :"<<endl;
if(sll                != 0) cout<<"sll               :"<<endl;
if(slt                != 0) cout<<"slt               :"<<endl;
if(sltu               != 0) cout<<"sltu              :"<<endl;
if(xor                != 0) cout<<"xor               :"<<endl;
if(srl                != 0) cout<<"srl               :"<<endl;
if(sra                != 0) cout<<"sra               :"<<endl;
if(or                 != 0) cout<<"or                :"<<endl;
if(and                != 0) cout<<"and               :"<<endl;
if(addiw              != 0) cout<<"addiw             :"<<endl;
if(slliw              != 0) cout<<"slliw             :"<<endl;
if(srliw              != 0) cout<<"srliw             :"<<endl;
if(sraiw              != 0) cout<<"sraiw             :"<<endl;
if(addw               != 0) cout<<"addw              :"<<endl;
if(subw               != 0) cout<<"subw              :"<<endl;
if(sllw               != 0) cout<<"sllw              :"<<endl;
if(srlw               != 0) cout<<"srlw              :"<<endl;
if(sraw               != 0) cout<<"sraw              :"<<endl;
if(lb                 != 0) cout<<"lb                :"<<endl;
if(lh                 != 0) cout<<"lh                :"<<endl;
if(lw                 != 0) cout<<"lw                :"<<endl;
if(ld                 != 0) cout<<"ld                :"<<endl;
if(lbu                != 0) cout<<"lbu               :"<<endl;
if(lhu                != 0) cout<<"lhu               :"<<endl;
if(lwu                != 0) cout<<"lwu               :"<<endl;
if(sb                 != 0) cout<<"sb                :"<<endl;
if(sh                 != 0) cout<<"sh                :"<<endl;
if(sw                 != 0) cout<<"sw                :"<<endl;
if(sd                 != 0) cout<<"sd                :"<<endl;
if(fence              != 0) cout<<"fence             :"<<endl;
if(fence_i            != 0) cout<<"fence_i           :"<<endl;
if(mul                != 0) cout<<"mul               :"<<endl;
if(mulh               != 0) cout<<"mulh              :"<<endl;
if(mulhsu             != 0) cout<<"mulhsu            :"<<endl;
if(mulhu              != 0) cout<<"mulhu             :"<<endl;
if(div                != 0) cout<<"div               :"<<endl;
if(divu               != 0) cout<<"divu              :"<<endl;
if(rem                != 0) cout<<"rem               :"<<endl;
if(remu               != 0) cout<<"remu              :"<<endl;
if(mulw               != 0) cout<<"mulw              :"<<endl;
if(divw               != 0) cout<<"divw              :"<<endl;
if(divuw              != 0) cout<<"divuw             :"<<endl;
if(remw               != 0) cout<<"remw              :"<<endl;
if(remuw              != 0) cout<<"remuw             :"<<endl;
if(lr_w               != 0) cout<<"lr_w              :"<<endl;
if(sc_w               != 0) cout<<"sc_w              :"<<endl;
if(lr_d               != 0) cout<<"lr_d              :"<<endl;
if(sc_d               != 0) cout<<"sc_d              :"<<endl;
if(ecall              != 0) cout<<"ecall             :"<<endl;
if(ebreak             != 0) cout<<"ebreak            :"<<endl;
if(uret               != 0) cout<<"uret              :"<<endl;
if(mret               != 0) cout<<"mret              :"<<endl;
if(dret               != 0) cout<<"dret              :"<<endl;
if(sfence_vma         != 0) cout<<"sfence_vma        :"<<endl;
if(wfi                != 0) cout<<"wfi               :"<<endl;
if(csrrw              != 0) cout<<"csrrw             :"<<endl;
if(csrrs              != 0) cout<<"csrrs             :"<<endl;
if(csrrc              != 0) cout<<"csrrc             :"<<endl;
if(csrrwi             != 0) cout<<"csrrwi            :"<<endl;
if(csrrsi             != 0) cout<<"csrrsi            :"<<endl;
if(csrrci             != 0) cout<<"csrrci            :"<<endl;
if(custom0            != 0) cout<<"custom0           :"<<endl;
if(custom0_rs1        != 0) cout<<"custom0_rs1       :"<<endl;
if(custom0_rs1_rs2    != 0) cout<<"custom0_rs1_rs2   :"<<endl;
if(custom0_rd         != 0) cout<<"custom0_rd        :"<<endl;
if(custom0_rd_rs1     != 0) cout<<"custom0_rd_rs1    :"<<endl;
if(custom0_rd_rs1_rs2 != 0) cout<<"custom0_rd_rs1_rs2:"<<endl;
if(custom1            != 0) cout<<"custom1           :"<<endl;
if(custom1_rs1        != 0) cout<<"custom1_rs1       :"<<endl;
if(custom1_rs1_rs2    != 0) cout<<"custom1_rs1_rs2   :"<<endl;
if(custom1_rd         != 0) cout<<"custom1_rd        :"<<endl;
if(custom1_rd_rs1     != 0) cout<<"custom1_rd_rs1    :"<<endl;
if(custom1_rd_rs1_rs2 != 0) cout<<"custom1_rd_rs1_rs2:"<<endl;
if(custom2            != 0) cout<<"custom2           :"<<endl;
if(custom2_rs1        != 0) cout<<"custom2_rs1       :"<<endl;
if(custom2_rs1_rs2    != 0) cout<<"custom2_rs1_rs2   :"<<endl;
if(custom2_rd         != 0) cout<<"custom2_rd        :"<<endl;
if(custom2_rd_rs1     != 0) cout<<"custom2_rd_rs1    :"<<endl;
if(custom2_rd_rs1_rs2 != 0) cout<<"custom2_rd_rs1_rs2:"<<endl;
if(custom3            != 0) cout<<"custom3           :"<<endl;
if(custom3_rs1        != 0) cout<<"custom3_rs1       :"<<endl;
if(custom3_rs1_rs2    != 0) cout<<"custom3_rs1_rs2   :"<<endl;
if(custom3_rd         != 0) cout<<"custom3_rd        :"<<endl;
if(custom3_rd_rs1     != 0) cout<<"custom3_rd_rs1    :"<<endl;
if(custom3_rd_rs1_rs2 != 0) cout<<"custom3_rd_rs1_rs2:"<<endl;
if(slli_rv32          != 0) cout<<"slli_rv32         :"<<endl;
if(srli_rv32          != 0) cout<<"srli_rv32         :"<<endl;
if(srai_rv32          != 0) cout<<"srai_rv32         :"<<endl;
if(rdcycle            != 0) cout<<"rdcycle           :"<<endl;
if(rdtime             != 0) cout<<"rdtime            :"<<endl;
if(rdinstret          != 0) cout<<"rdinstret         :"<<endl;
if(rdcycleh           != 0) cout<<"rdcycleh          :"<<endl;
if(rdtimeh            != 0) cout<<"rdtimeh           :"<<endl;
if(rdinstreth         != 0) cout<<"rdinstreth        :"<<endl;

*/

/*

if(beq                != 0) cout<<"beq:"<<endl;
if(bne                != 0) cout<<"bne:"<<endl;
if(blt                != 0) cout<<"blt:"<<endl;
if(bge                != 0) cout<<"bge:"<<endl;
if(bltu               != 0) cout<<"bltu:"<<endl;
if(bgeu               != 0) cout<<"bgeu:"<<endl;
if(jalr               != 0) cout<<"jalr:"<<endl;
if(jal                != 0) cout<<"jal:"<<endl;
if(lui                != 0) cout<<"lui:"<<endl;
if(auipc              != 0) cout<<"auipc:"<<endl;
if(addi               != 0) cout<<"addi:"<<endl;
if(slli               != 0) cout<<"slli:"<<endl;
if(slti               != 0) cout<<"slti:"<<endl;
if(sltiu              != 0) cout<<"sltiu:"<<endl;
if(xori               != 0) cout<<"xori:"<<endl;
if(srli               != 0) cout<<"srli:"<<endl;
if(srai               != 0) cout<<"srai:"<<endl;
if(ori                != 0) cout<<"ori:"<<endl;
if(andi               != 0) cout<<"andi:"<<endl;
if(add                != 0) cout<<"add:"<<endl;
if(sub                != 0) cout<<"sub:"<<endl;
if(sll                != 0) cout<<"sll:"<<endl;
if(slt                != 0) cout<<"slt:"<<endl;
if(sltu               != 0) cout<<"sltu:"<<endl;
if(xor                != 0) cout<<"xor:"<<endl;
if(srl                != 0) cout<<"srl:"<<endl;
if(sra                != 0) cout<<"sra:"<<endl;
if(or                 != 0) cout<<"or:"<<endl;
if(and                != 0) cout<<"and:"<<endl;
if(addiw              != 0) cout<<"addiw:"<<endl;
if(slliw              != 0) cout<<"slliw:"<<endl;
if(srliw              != 0) cout<<"srliw:"<<endl;
if(sraiw              != 0) cout<<"sraiw:"<<endl;
if(addw               != 0) cout<<"addw:"<<endl;
if(subw               != 0) cout<<"subw:"<<endl;
if(sllw               != 0) cout<<"sllw:"<<endl;
if(srlw               != 0) cout<<"srlw:"<<endl;
if(sraw               != 0) cout<<"sraw:"<<endl;
if(lb                 != 0) cout<<"lb:"<<endl;
if(lh                 != 0) cout<<"lh:"<<endl;
if(lw                 != 0) cout<<"lw:"<<endl;
if(ld                 != 0) cout<<"ld:"<<endl;
if(lbu                != 0) cout<<"lbu:"<<endl;
if(lhu                != 0) cout<<"lhu:"<<endl;
if(lwu                != 0) cout<<"lwu:"<<endl;
if(sb                 != 0) cout<<"sb:"<<endl;
if(sh                 != 0) cout<<"sh:"<<endl;
if(sw                 != 0) cout<<"sw:"<<endl;
if(sd                 != 0) cout<<"sd:"<<endl;
if(fence              != 0) cout<<"fence     :"<<endl;
if(fence_i            != 0) cout<<"fence_i   :"<<endl;
if(mul                != 0) cout<<"mul       :"<<endl;
if(mulh               != 0) cout<<"mulh      :"<<endl;
if(mulhsu             != 0) cout<<"mulhsu    :"<<endl;
if(mulhu              != 0) cout<<"mulhu     :"<<endl;
if(div                != 0) cout<<"div       :"<<endl;
if(divu               != 0) cout<<"divu      :"<<endl;
if(rem                != 0) cout<<"rem       :"<<endl;
if(remu               != 0) cout<<"remu:"<<endl;
if(mulw               != 0) cout<<"mulw:"<<endl;
if(divw               != 0) cout<<"divw:"<<endl;
if(divuw              != 0) cout<<"divuw:"<<endl;
if(remw               != 0) cout<<"remw:"<<endl;
if(remuw              != 0) cout<<"remuw:"<<endl;
if(lr_w               != 0) cout<<"lr_w:"<<endl;
if(sc_w               != 0) cout<<"sc_w:"<<endl;
if(lr_d               != 0) cout<<"lr_d:"<<endl;
if(sc_d               != 0) cout<<"sc_d:"<<endl;
if(ecall              != 0) cout<<"ecall:"<<endl;
if(ebreak             != 0) cout<<"ebreak:"<<endl;
if(uret               != 0) cout<<"uret:"<<endl;
if(mret               != 0) cout<<"mret:"<<endl;
if(dret               != 0) cout<<"dret:"<<endl;
if(sfence_vma         != 0) cout<<"sfence_vma:"<<endl;
if(wfi                != 0) cout<<"wfi:"<<endl;
if(csrrw              != 0) cout<<"csrrw:"<<endl;
if(csrrs              != 0) cout<<"csrrs:"<<endl;
if(csrrc              != 0) cout<<"csrrc:"<<endl;
if(csrrwi             != 0) cout<<"csrrwi:"<<endl;
if(csrrsi             != 0) cout<<"csrrsi:"<<endl;
if(csrrci             != 0) cout<<"csrrci:"<<endl;
if(custom0            != 0) cout<<"custom0   :"<<endl;
if(custom0_rs1        != 0) cout<<"custom0_rs1       :"<<endl;
if(custom0_rs1_rs2    != 0) cout<<"custom0_rs1_rs2   :"<<endl;
if(custom0_rd         != 0) cout<<"custom0_rd        :"<<endl;
if(custom0_rd_rs1     != 0) cout<<"custom0_rd_rs1    :"<<endl;
if(custom0_rd_rs1_rs2 != 0) cout<<"custom0_rd_rs1_rs2:"<<endl;
if(custom1            != 0) cout<<"custom1           :"<<endl;
if(custom1_rs1        != 0) cout<<"custom1_rs1       :"<<endl;
if(custom1_rs1_rs2    != 0) cout<<"custom1_rs1_rs2   :"<<endl;
if(custom1_rd         != 0) cout<<"custom1_rd        :"<<endl;
if(custom1_rd_rs1     != 0) cout<<"custom1_rd_rs1    :"<<endl;
if(custom1_rd_rs1_rs2 != 0) cout<<"custom1_rd_rs1_rs2:"<<endl;
if(custom2            != 0) cout<<"custom2           :"<<endl;
if(custom2_rs1        != 0) cout<<"custom2_rs1       :"<<endl;
if(custom2_rs1_rs2    != 0) cout<<"custom2_rs1_rs2   :"<<endl;
if(custom2_rd         != 0) cout<<"custom2_rd        :"<<endl;
if(custom2_rd_rs1     != 0) cout<<"custom2_rd_rs1    :"<<endl;
if(custom2_rd_rs1_rs2 != 0) cout<<"custom2_rd_rs1_rs2:"<<endl;
if(custom3            != 0) cout<<"custom3           :"<<endl;
if(custom3_rs1        != 0) cout<<"custom3_rs1       :"<<endl;
if(custom3_rs1_rs2    != 0) cout<<"custom3_rs1_rs2   :"<<endl;
if(custom3_rd         != 0) cout<<"custom3_rd        :"<<endl;
if(custom3_rd_rs1     != 0) cout<<"custom3_rd_rs1    :"<<endl;
if(custom3_rd_rs1_rs2 != 0) cout<<"custom3_rd_rs1_rs2:"<<endl;
if(slli_rv32          != 0) cout<<"slli_rv32         :"<<endl;
if(srli_rv32          != 0) cout<<"srli_rv32         :"<<endl;
if(srai_rv32          != 0) cout<<"srai_rv32         :"<<endl;
if(rdcycle            != 0) cout<<"rdcycle           :"<<endl;
if(rdtime             != 0) cout<<"rdtime            :"<<endl;
if(rdinstret          != 0) cout<<"rdinstret         :"<<endl;
if(rdcycleh           != 0) cout<<"rdcycleh          :"<<endl;
if(rdtimeh            != 0) cout<<"rdtimeh           :"<<endl;
if(rdinstreth         != 0) cout<<"rdinstreth        :"<<endl;

*/



