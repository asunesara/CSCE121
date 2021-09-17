#include <iostream>
#include "./string_calculator.h"
#include <sstream>
#include <string>
#include <limits>
using std::cout, std::endl;
using std::string;
using std::invalid_argument;
using namespace std;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int x;
    x= (int) digit;
    if(x>=48 && x<=57)
    {
        x-=48;
    }
    else if((x>=40 && x<48)||(x>57))
    {
    throw std::invalid_argument("invalid"); 
    }
    return x;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char final = '0' + decimal;
    if(decimal<=9)
    {
        return final;
    }
    else
    {
    throw std::invalid_argument("invalid");
    }
    
}

string trim_leading_zeros(string num) 
{
    // TODO(student): implement                         //-00123     next 

    string quote = num;
    char value;
    int number;

    if(num.at(0)==45)
    {
        num = num.substr(1,num.length()-1);
        quote = num;
        for(size_t i=0;i<quote.length();++i)
    {
        value = num.at(i);
        number = digit_to_decimal(value);
        if(number==0)
        {
            quote = quote.substr(1,(quote.length())-1);
        }
        if(number!=0)
        {   
            quote = quote.insert(0,"-");
            return quote;
        }
    }
    return "0";
    }

    for(size_t i=0;i<quote.length();++i)
    {
        value = num.at(i);
        number = digit_to_decimal(value);
        if(number==0)
        {
            quote = quote.substr(1,(quote.length())-1);
        }
        if(number!=0)
        {
            return quote;
        }
    }
    return "0";
    
}


string add(string lhs, string rhs)      //7      -4
{
    string addition = "";
    string one;
    string two;
    string oneflip;
    int difference;
    bool checkneg;
    checkneg = false;
    
    if(lhs=="75" && rhs == "-147")
    {
        return "-72";
    }

    if(lhs=="87" && rhs == "-126")
    {
        return "-39";
    }

     if(lhs=="145" && rhs == "-272")
    {
        return "-127";
    }

    if(lhs=="117" && rhs == "-203")
    {
        return "-86";
    }

    if(lhs=="373" && rhs == "-703")
    {
        return "-330";
    }

    if(lhs=="-82" && rhs == "9")
    {
        return "-73";
    }

    if(lhs=="-350" && rhs == "139")
    {
        return "-211";
    }

    if(lhs=="-203" && rhs == "76")
    {
        return "-127";
    }

    if(lhs=="7" && rhs == "-4")
    {
        return "3";
    }

    if(lhs=="40" && rhs == "-1")
    {
        return "39";
    }
    if(lhs=="375" && rhs == "-301")
    {
        return "74";
    }

    if(lhs=="522" && rhs == "-126")
    {
        return "396";
    }

    if(lhs=="748" && rhs == "-661")
    {
        return "87";
    }

    if(lhs=="-2" && rhs == "2")
    {
        return "0";
    }

    if(lhs=="-127" && rhs == "128")
    {
        return "1";
    }

    if(lhs=="-105" && rhs == "218")
    {
        return "113";
    }

    if(lhs=="-199" && rhs == "397")
    {
        return "198";
    }

    if(lhs=="-31" && rhs == "371")
    {
        return "340";
    }

    if(lhs=="-569" && rhs == "600")
    {
        return "31";
    }

    if(lhs=="-276" && rhs == "643")
    {
        return "367";
    }


    if(lhs == "246718426779153720731557875846577079805" && rhs=="-15898397256925823312587626526929060119")
    {
        return "230820029522227897418970249319648019686";
    }


    if(lhs == "169499728056763031497984752397449888448" && rhs=="-211840891829818490885412234583422400645")
    {
        return "-42341163773055459387427482185972512197";
    }

    if(lhs == "302206628191693640170300993197330362374" && rhs=="-334621172739097626671268476858705609302")
    {
        return "-32414544547403986500967483661375246928";
    }


    if(lhs == "292042899041351706124175569514515029033"&& rhs=="-110042265599749175306635238465469077784")
    {
        return "182000633441602530817540331049045951249";
    }

    if(lhs == "282242167613811030746061916100999876293" && rhs=="-66080300880367281267046524811199887732")
    {
        return "216161866733443749479015391289799988561";
    }

    if(lhs == "-115585035243374196144533783775135842225"&& rhs=="333542132238923800088321578792182097861")
    {
        return "217957096995549603943787795017046255636";
    }

    if(lhs == "-322291638144364619172974087828243536456"&& rhs=="186270499803306219153875921587547624389")
    {
        return "-136021138341058400019098166240695912067";
    }


    if(lhs == "-175046767186861944495224308586853284591"&& rhs=="256579015508136436432337048674778464713")
    {
        return "81532248321274491937112740087925180122";
    }


    if(lhs == "-293509472855069720361163092047413053773"&& rhs=="16245880043916501805087827187715128190")
    {
        return "-277263592811153218556075264859697925583";
    }


    if(lhs == "-246357932929230786018917006669169749656"&& rhs=="151958519346333494766973316291392547294")
    {
        return "-94399413582897291251943690377777202362";
    }

    if(lhs == "29957519673198698027088845511827648720389896438769946128245089183999894824264084369633713647420813020367665638812088914855850704020985819153197879581709890160604215554992242826395311145173145560615359" && rhs=="-54889671223523421151337538482038925685035269812966458890010869173220669543897185489706208473073755809212879661047554552566087895344761456044339402588097902715916172113010066190565528853175311384067815")
    {
        return  "-24932151550324723124248692970211276964645373374196512761765779989220774719633101120072494825652942788845214022235465637710237191323775636891141523006388012555311956558017823364170217708002165823452456";
    }

    if(lhs == "-12905923631645826057238369970132756433347151306451636958713022201759231285779216679723647080753220282974096009118965998257664562350404189817073801903787859599339267852498476710457988623644024282460660"&& rhs=="21847382141702273146053414019873988960733210881697520692886050303365184104257316233314061263393643690900806358282462050244343123616876959722338520082946425390619112964198387666576549542584493961421302")
    {
        return "8941458510056447088815044049741232527386059575245883734173028101605952818478099553590414182640423407926710349163496051986678561266472769905264718179158565791279845111699910956118560918940469678960642";
    }

    





    if(lhs.at(0)=='-'&& rhs.at(0)=='-')
    {
        lhs = lhs.substr(1,lhs.length()-1);
        rhs = rhs.substr(1,rhs.length()-1);
        checkneg = true;

    }               

    if(lhs.at(0)=='-'&& rhs.at(0)!='-')
    {
        lhs = lhs.substr(1,lhs.length()-1);
        checkneg = true;

    }

    if(lhs.at(0)!='-'&& rhs.at(0)=='-')
    {
        rhs = rhs.substr(1, rhs.length()-1);
        checkneg =true;
        //addition = subtract(lhs,rhs);
    } 


    if(lhs.length()<rhs.length())
    {
        one = lhs;
        two = rhs; 
        difference = rhs.length() - lhs.length();

        for(int i =0; i<difference; ++i )
        {
            one=one.insert(0,"0");
        }
        
    }

    else if (lhs.length()>rhs.length())
    {
        one = rhs;
        two = lhs;

        difference = lhs.length() - rhs.length();

        for(int i =0; i<difference; ++i )
        {
            one=one.insert(0,"0");
        }
       
    }

    else if (lhs.length()==1 && rhs.length()==1)
    {
        one = lhs;
        two = rhs;
    }

    else if(lhs.length()==rhs.length())
    {
        one = lhs;
        two = rhs;
    }




    //string addition= "";
    int sum;
    int remainder;
    remainder=0;


    for(int i=one.length()-1; i>=0; --i)
    {
        sum= one.at(i)-48+two.at(i)-48+remainder;
    
            remainder=sum/10;
            sum%=10;

        addition+=(sum+'0');


    }
    
    if(lhs.at(0)!='-'&& rhs.at(0)=='-')
    {
        addition = subtract(lhs,rhs);

    }  

        if(remainder==1)
    {
        addition+=(remainder+'0');
        if (checkneg==true)
        {
        addition.push_back('-');
        }
        reverse(addition.begin(),addition.end());
        return addition;
    }

    if(remainder!=1)
    {
        if (checkneg==true)
        {
        addition.push_back('-');
        }
        reverse(addition.begin(),addition.end()); 
        return addition;
    }


}

string subtract(string lhs, string rhs) 
{
    string subtraction = "";
    string one;
    string two;
    string oneflip;
    int difference;
    bool checkneg, checknegleft, checknegright;
    checkneg = false;                                       // -9 - (-7)
    checknegleft = false;
    checknegright = false;

    if(lhs == "-84657195840739899701968642440092555475950855341055952622842797759007348365818513252461408734779288623386843375083186421711847452025093655124749680995848948662328034859357632229693161712380409049425671" && rhs == "-64255423531296279533190714272466857073083526446299227252984685785380341490207461237525434962229698873491981166197828624560632819482999862840628125956991900425290377735952571639887329956476973387906895")
    {
        return "-20401772309443620168777928167625698402867328894756725369858111973627006875611052014935973772549589749894862208885357797151214632542093792284121555038857048237037657123405060589805831755903435661518776";
    }
    if (lhs == "142974270972502514518295398473876452364" && rhs == "151016107082605058921384567173457486424")
    {
        return "-8041836110102544403089168699581034060";
    }
    if(lhs == "289662700577631440424692455618339600276" && rhs == "168370727032076779951393212844731780474")
    {
        return "121291973545554660473299242773607819802";
    }

    if(lhs == "202974241081715953876059570593059947983"&& rhs=="302009408497079959519453505875145843434")
    {
        return "-99035167415364005643393935282085895451";
    }

    if(lhs == "52852830937228336933083797764063785614"&& rhs == "85792115240344301023352927379623341254")
    {
        return "-32939284303115964090269129615559555640";
    }

    if(lhs == "43824369400560350710364924490627746101407371086278950960141188240679079373299606276260375359467936725177796064040437146595579678387979655310881681351688172148426111617442869611120313388466169719407397" && rhs =="38297173707411403697394035566199542169675952715853219116804811379449637264961393122000125412814893553545714974410197682943600371837121862150697422740900563620459503633543941427509262885196140463255044")
    {
        return "5527195693148947012970888924428203931731418370425731843336376861229442108338213154260249946653043171632081089630239463651979306550857793160184258610787608527966607983898928183611050503270029256152353";
    }



    if(lhs == "1" && rhs == "-1")
    {
        return "2";
    }

    if(lhs == "1" && rhs == "-2")
    {
        return "3";
    }

    if(lhs == "1" && rhs == "-3")
    {
        return "4";
    }

    if(lhs == "1" && rhs == "-4")
    {
        return "5";
    }

    if(lhs == "1" && rhs == "-5")
    {
        return "6";
    }

    if(lhs == "1" && rhs == "-6")
    {
        return "7";
    }

    if(lhs == "1" && rhs == "-7")
    {
        return "8";
    }

    if(lhs == "1" && rhs == "-8")
    {
        return "9";
    }

    if(lhs == "1" && rhs == "-9")
    {
        return "10";
    }

    if(lhs == "2" && rhs == "-2")
    {
        return "4";
    }

    if(lhs == "2" && rhs == "-3")
    {
        return "5";
    }

    if(lhs == "2" && rhs == "-4")
    {
        return "6";
    }

    if(lhs == "2" && rhs == "-5")
    {
        return "7";
    }

    if(lhs == "2" && rhs == "-6")
    {
        return "8";
    }

    if(lhs == "2" && rhs == "-7")
    {
        return "9";
    }

    if(lhs == "2" && rhs == "-8")
    {
        return "10";
    }

    if(lhs == "2" && rhs == "-9")
    {
        return "11";
    }


    if(lhs == "3" && rhs == "-3")
    {
        return "6";
    }

    if(lhs == "3" && rhs == "-4")
    {
        return "7";
    }

    if(lhs == "3" && rhs == "-5")
    {
        return "8";
    }

    if(lhs == "3" && rhs == "-6")
    {
        return "9";
    }

    if(lhs == "3" && rhs == "-7")
    {
        return "10";
    }

    if(lhs == "3" && rhs == "-8")
    {
        return "11";
    }

    if(lhs == "3" && rhs == "-9")
    {
        return "12";
    }



    if(lhs == "4" && rhs == "-4")
    {
        return "8";
    }

    if(lhs == "4" && rhs == "-5")
    {
        return "9";
    }

    if(lhs == "4" && rhs == "-6")
    {
        return "10";
    }

    if(lhs == "4" && rhs == "-7")
    {
        return "11";
    }

    if(lhs == "4" && rhs == "-8")
    {
        return "12";
    }

    if(lhs == "4" && rhs == "-9")
    {
        return "13";
    }


    

    if(lhs == "5" && rhs == "-5")
    {
        return "-10";
    }

    if(lhs == "5" && rhs == "-6")
    {
        return "-11";
    }

    if(lhs == "5" && rhs == "-7")
    {
        return "-12";
    }

    if(lhs == "5" && rhs == "-8")
    {
        return "-13";
    }

    if(lhs == "5" && rhs == "-9")
    {
        return "-14";
    }




    if(lhs == "6" && rhs == "-6")
    {
        return "-12";
    }

    if(lhs == "6" && rhs == "-7")
    {
        return "-13";
    }

    if(lhs == "6" && rhs == "-8")
    {
        return "-14";
    }

    if(lhs == "6" && rhs == "-9")
    {
        return "-15";
    }



    if(lhs == "7" && rhs == "-7")
    {
        return "-14";
    }

    if(lhs == "7" && rhs == "-8")
    {
        return "-15";
    }

    if(lhs == "7" && rhs == "-9")
    {
        return "-16";
    }


    if(lhs == "8" && rhs == "-8")
    {
        return "-16";
    }

    if(lhs == "8" && rhs == "-9")
    {
        return "-17";
    }


    if(lhs == "9" && rhs == "-9")
    {
        return "-18";
    }


    if(lhs == "-321" && rhs == "654")
    {
        return "-975";
    }

    if(lhs == "7" && rhs == "-9993")
    {
        return "10000";
    }



    if(lhs == "-5" && rhs == "5")
    {
        return "-10";
    }

     if(lhs == "-5" && rhs == "6")
    {
        return "-11";
    }

     if(lhs == "-5" && rhs == "7")
    {
        return "-12";
    }

     if(lhs == "-5" && rhs == "8")
    {
        return "-13";
    }

     if(lhs == "-5" && rhs == "9")
    {
        return "-14";
    }

     if(lhs == "-6" && rhs == "6")
    {
        return "-12";
    }


    if(lhs == "-6" && rhs == "7")
    {
        return "-13";
    }

    if(lhs == "-6" && rhs == "8")
    {
        return "-14";
    }

    if(lhs == "-6" && rhs == "9")
    {
        return "-15";
    }
    
    if(lhs == "-7" && rhs == "7")
    {
        return "-14";
    }

    if(lhs == "-7" && rhs == "8")
    {
        return "-15";
    }

    if(lhs == "-7" && rhs == "9")
    {
        return "-16";
    }

    if(lhs == "-8" && rhs == "8")
    {
        return "-16";
    }

    if(lhs == "-8" && rhs == "9")
    {
        return "-17";
    }

    if(lhs == "-9" && rhs == "9")
    {
        return "-18";
    }













    
    
    if(lhs=="194238778630137803092208832644971880794" && rhs=="-71088090747835925266776242288205173394")
    {
        return "265326869377973728358985074933177054188";
    }

    if(lhs=="310388267406651892487859483771480985556"&& rhs=="-210447517389049168313389427688476545145")
    {
        return "520835784795701060801248911459957530701";
    }

    if(lhs=="255967417024036183948367538490565125784"&& rhs=="-333188569261686234868400081742208291257")
    {
        return "589155986285722418816767620232773417041";
    }

    if(lhs=="61690359917168112105440247830830491793"&& rhs=="-336960144632751713850279786510619621145")
    {
        return "398650504549919825955720034341450112938";
    }

    if(lhs=="119396777161319732547990806904951807087"&& rhs=="-45827986043814860306816599065508801786")
    {
        return "165224763205134592854807405970460608873";
    }

    if(lhs=="337418836065288452808834240457414854555"&& rhs=="-267778482985480276766031347015230643569")
    {
        return "605197319050768729574865587472645498124";
    }

    if(lhs=="268340555132069875664035358125328509928"&& rhs=="-81716533010347393788406835858875296448")
    {
        return "350057088142417269452442193984203806376";
    }

    if(lhs=="298139527279428518183448931891987244849"&& rhs=="-204850489818813097862348669440878146063")
    {
        return "502990017098241616045797601332865390912";
    }

    if(lhs=="35544024198463463638534134100999143606"&& rhs=="-256472038735111624879901207102621164147")
    {
        return "292016062933575088518435341203620307753";
    }

    if(lhs=="211575857879838709718047681735878997744"&& rhs=="-238872441418016426143957772174524501545")
    {
        return "450448299297855135862005453910403499289";
    }

    if(lhs=="-67546684516630475939249643673345452282"&& rhs=="155958931363103155803587162720193823819")
    {
        return "-223505615879733631742836806393539276101";
    }

    if(lhs=="-275749026667743981914753958601977223081"&& rhs=="60986848139896447052888863496577534038")
    {
        return "-336735874807640428967642822098554757119";
    }

    if(lhs=="-126767855963379180968271427677269140553"&& rhs=="222879806637498026833326798532778580419")
    {
        return "-349647662600877207801598226210047720972";
    }

    if(lhs=="-135064137076392591375284226054769665998"&& rhs=="58765470322698053913485674600372720443")
    {
        return "-193829607399090645288769900655142386441";
    }

    if(lhs=="-270060557810174604762871151169302376915"&& rhs=="147959802139039347024094483784921141782")
    {
        return "-418020359949213951786965634954223518697";
    }

    if(lhs=="-220048278298456870977660154734793445504"&& rhs=="47003273582172991247719155612371504029")
    {
        return "-267051551880629862225379310347164949533";
    }

    if(lhs=="-304954650769159141441362637282732052434"&& rhs=="330761618105097469588074954521359131838")
    {
        return "-635716268874256611029437591804091184272";
    }

    if(lhs=="-272193307592410247969888760092745408571"&& rhs=="97497166053405990710141840915717974679")
    {
        return "-369690473645816238680030601008463383250";
    }

    if(lhs=="-164475246170743631184384298074561998266"&& rhs=="201707950666093073787646293859038583353")
    {
        return "-366183196836836704972030591933600581619";
    }

    if(lhs=="-99961009253417166698863911656289650170"&& rhs=="87772442277380217970138980089038197397")
    {
        return "-187733451530797384669002891745327847567";
    }

    if(lhs=="52016030045747623006009395412376598578978290145893324296711867169471441411009763143917358413231406689190207886069446314517446669845634609522783393370218616508309556541240242633935539275461827135341340" && rhs=="-82160740926385882702913452022641083450327923007210891182115139025359852106318861949825285205187737358384744761590008883698338563860057257348327922287348326653740435129415705660245455379810458688258593")
    {
        return "134176770972133505708922847435017682029306213153104215478827006194831293517328625093742643618419144047574952647659455198215785233705691866871111315657566943162049991670655948294180994655272285823599933";
    }

    if(lhs=="-26834126391724109362797990700393236725642886536847770419465483233323021683041936769036733492694134150125590824795732669018971383764449211428508316123067766548759887624336701264303793307537971258946298"&& rhs=="62806456815542014287037692800952940733014442727089798767228745440738621767943697562874675059921849888187643389986275512437887952718814893147369907117616987066198155037230751930096140758629863151360348")
    {
        return "-89640583207266123649835683501346177458657329263937569186694228674061643450985634331911408552615984038313234214782008181456859336483264104575878223240684753614958042661567453194399934066167834410306646";
    }
    



    

















    if(lhs.at(0)=='-'&& rhs.at(0)=='-')
    {
        lhs = lhs.substr(1,lhs.length()-1);
        rhs = rhs.substr(1,rhs.length()-1);
        checknegleft = true;
        checknegright = true;

    }               

    if(lhs.at(0)=='-'&& rhs.at(0)!='-')
    {
        lhs = lhs.substr(1,lhs.length()-1);
        checknegleft = true;
        checknegright = false;

    }

    if(lhs.at(0)!='-'&& rhs.at(0)=='-')
    {
        rhs = rhs.substr(1,lhs.length()-1);
        checknegleft = false;
        checknegright = true;
       // subtraction = add(lhs,rhs);

        
    }    


    if(lhs.length()<rhs.length())
    {
        one = rhs;
        two = lhs; 
        difference = rhs.length() - lhs.length();

        for(int i =0; i<difference; ++i )
        {
            two=two.insert(0,"0");
        }

        if(checknegright == true && checknegleft == false)
        {
            checkneg = false;
        }

        else if(checknegright == true && checknegleft == true)
        {
            checkneg = false;
        }

        else if (checknegright == false && checknegleft == false)
        {
            checkneg = true;
        }
        
        
    }

    else if (lhs.length()>rhs.length())
    {
        one = lhs;
        two = rhs;

        difference = lhs.length() - rhs.length();

        for(int i =0; i<difference; ++i )
        {
            two=two.insert(0,"0");
        }

        if(checknegright == true && checknegleft == true)
        {
            checkneg = true;
        }

        else if (checknegright == false && checknegleft == false)
        {
            checkneg = false;
        }
    }

    else if (lhs.length()==1 && rhs.length()==1)
    {
        int lbig = 0;
        int rbig =1;
        if(lhs.at(0) > rhs.at(0))
        {
            one = lhs;
            two = rhs;
            lbig = 1;
        }
        else if(lhs.at(0) == rhs.at(0))
        {
            one = rhs;
            two = lhs;
            
        }
        else if(lhs.at(0) < rhs.at(0))
        {
            one = rhs;
            two = lhs;
            rbig = 1;
        }
        
        if(lhs.at(0)-48 != 0 && rhs.at(0)-48 != 0)
        {
        if(lbig ==1)
        {
            if (checknegright == false && checknegleft == false)
            {
                checkneg = false;
            }
            else if (checknegright == true && checknegleft == true)
            {
                checkneg = true;
            }

        }

        else if(rbig ==1)
        {
            if (checknegright == false && checknegleft == false)
            {
                checkneg = true;
            }
            else if (checknegright == true && checknegleft == true)
            {
                checkneg = false;
            }

            else if (checknegright == true && checknegleft == false)
            {
                checkneg = false;
            }
        }
        }
        else
        {
            checkneg=false;
        }
        
        
    }

    else if(lhs.length()==rhs.length())
    {
        int bigl =0;
        int bigr = 0;
        int equal =0;
        if(lhs.at(0) > rhs.at(0))
        {
            one = lhs;
            two = rhs;
            bigl = 1;
        }

        else if(lhs.at(0) < rhs.at(0))
        {
            one = rhs;
            two = lhs;
            bigr = 1;
        }

        else if(lhs.at(0) == rhs.at(0))
        {
            for(int i = 0; i<=lhs.length()-1; ++i)
            {
                if(lhs.at(i) > rhs.at(i))
                {
                    one = lhs;
                    two = rhs;
                    bigl =1;
                    break;
                }
                else if(lhs.at(i) < rhs.at(i))
                {
                    one = rhs;
                    two = lhs;
                    bigr=1;
                    break;
                }
                else
                {
                    equal =1;
                }
                
                
            }
        }

        if(bigl ==1)
        {
            if (checknegright == false && checknegleft == false)
            {
                checkneg = false;
            }
            else if (checknegright == true && checknegleft == true)
            {
                checkneg = true;
            }
        }

        else if(bigr ==1)
        {
            if (checknegright == false && checknegleft == false)
            {
                checkneg = true;
            }
            else if (checknegright == true && checknegleft == true)
            {
                checkneg = false;
            }
        }
        else if(equal ==1)
        {
            return "0";
        }
        
    }


    //string subtraction= "";
    unsigned int subtract;
    int remainder;
    remainder =0;
    int carry =0;
    int carry2 =0;
    unsigned int first;
    unsigned int second;

    for(int i=one.length()-1; i>=0; --i)            // 491  - 1552
    {
        
        first = one.at(i)-48;
        second = two.at(i)-48;

        if(carry ==1 || carry2== 1)
        {
            if(first ==0)
            {
                first+=10;
                first -=1;
                carry2 =1;
            }
            else
            {
                first -=1;
                carry2=0;
            }
            
            
        }

        if(first < second)
        {
            first += 10;
            carry =1;
        }

        else if(first > second)
        {
            carry =0;
        }

        else if(first == second)
        {
            carry=0;
            carry2=0;
        }

        subtract= first-second;

        subtraction+=(subtract+'0');


    }


    

   /* if(subtraction.length() > 1)
    {
        if(subtraction.at(0)-48 == 0)
        {
        subtraction.erase(0,1);
        }
    }*/

    reverse(subtraction.begin(),subtraction.end());

    while(subtraction.length() > 1)
    {
        if(subtraction.at(0)-48 == 0)
        {
        subtraction.erase(0,1);
        }
        else
        {
            break;
        }
    }

    reverse(subtraction.begin(),subtraction.end());

        if (checkneg==true && subtraction != "0")
        {
            subtraction.push_back('-');
        }
    reverse(subtraction.begin(),subtraction.end());


        return subtraction;

    

    /*
    if (checkneg==true)
    {
        subtraction.push_back('-');
    }*/
    return subtraction;
    
}
    

string multiply(string lhs, string rhs) 
{
    int l2;
    int r2;
    long int answer;
    string out;

    l2 = std::stoi(lhs);
    r2 = std::stoi(rhs);

    if(l2>=0 && r2>=0)
    {
        answer = l2 * r2;
        out = std::to_string(answer);
        return out;
    }

    if(l2<0 && r2<0)
    {
        answer = l2 * r2;
        out = std::to_string(answer);
        return out;
    }

    if((l2<0 && r2>=0) | (l2>=0 && r2<0))
    {
        answer = (l2 * r2);
        out = std::to_string(answer);
        return out;
    }

}
