/* file generated by atan_ext.mpl*/

#include "double-extended.h"
#ifdef WORDS_BIGENDIAN
static const db_number HALFPI = {{0x3FF921FB,0x54442D18}};
#else
static const db_number HALFPI = {{0x54442D18,0x3FF921FB}};
#endif
#define MIN_REDUCTION_NEEDED 0.01269144369306618004077670910586377580133132772550
#define A 0
#define B 1
#define ATAN_BHI 2
#define ATAN_BLO 3
#define EPSILON 2.04221581890623872536809598138553304900554884091659e-19
#define EPSILON_NO_RED 1.56771350764719825686165002299335165493769973908433e-19
#define TWO_M_64 5.42101086242752217003726400434970855712890625000000e-20
#define TWO_10 1.02400000000000000000000000000000000000000000000000e+03
static long double const arctan_table[62][4] = 
{
{
/*a[0]     */ 1.26914436930661800407767091058637758013313277255025e-02L ,
/*b[0] :   */ 2.53869765124364010090284460990917025924318295437843e-02L ,
/*atan_b[0]*/ 2.53815246637655720121743178549489350359635864151642e-02L,-3.82867671985365148296195510993062067276578228375704e-22L ,
}
,{
/*a[1]     */ 3.80906929270782389081071355032096219670426556476096e-02L ,
/*b[1] :   */ 5.08066978456951537364380978162303748035810713190585e-02L ,
/*atan_b[1]*/ 5.07630493039637822849077710557486042830532824154943e-02L,-9.08476246908274392997382820602430859506166364517308e-22L ,
}
,{
/*a[2]     */ 6.35391122156262265073608708121557700191864542424734e-02L ,
/*b[2] :   */ 7.62920780032335878368971587848434978695877362042665e-02L ,
/*atan_b[2]*/ 7.61445739207162224570710207238732891710242256522179e-02L,-8.68282459278828642628371257575800957271427290973051e-22L ,
}
,{
/*a[3]     */ 8.90697640843219566678833329168019764753902351477774e-02L ,
/*b[3] :   */ 1.01876371166982943013764196377168858020922925788909e-01L ,
/*atan_b[3]*/ 1.01526098514204888296065358577191517497340100817382e-01L,2.45769122345174324242177208623096072189462913881225e-21L ,
}
,{
/*a[4]     */ 1.14716138034642069137320417229771403756391587930350e-01L ,
/*b[4] :   */ 1.27593346472767313573462404086011900972152943722904e-01L ,
/*atan_b[4]*/ 1.26907623084671710832899149679064976226072758436203e-01L,-2.78816905606569560493152971332904010388470569035556e-21L ,
}
,{
/*a[5]     */ 1.40512327929006402335609329563511567374816039056592e-01L ,
/*b[5] :   */ 1.53477468508642290209546821255770510106231085956097e-01L ,
/*atan_b[5]*/ 1.52289147632417933012007223159134383649870869703591e-01L,5.68472586734099921502541679282214217956262541061124e-21L ,
}
,{
/*a[6]     */ 1.66493216120905508290155447580666771977220433369075e-01L ,
/*b[6] :   */ 1.79564085612852898464876852391292061383865075185895e-01L ,
/*atan_b[6]*/ 1.77670672157803333676934047502538049911890993826091e-01L,2.87836193526503867133275526409685067962483884000160e-22L ,
}
,{
/*a[7]     */ 1.92694666476959811837109742880645880397828687778289e-01L ,
/*b[7] :   */ 2.05889628199360004388320487256347490756525075994432e-01L ,
/*atan_b[7]*/ 2.03052196661245300563923728287551995208559674210846e-01L,6.51289679452996937811343386488447297822880946308131e-21L ,
}
,{
/*a[8]     */ 2.19153728611415853112422718806867132089178565966211e-01L ,
/*b[8] :   */ 2.32491819536184162126382646285094324412057176232338e-01L ,
/*atan_b[8]*/ 2.28433721143217755085073027154773939173537655733526e-01L,-3.99672208045526890632745378555235922768746788959726e-21L ,
}
,{
/*a[9]     */ 2.45908855876056427513150499868929834361055540260207e-01L ,
/*b[9] :   */ 2.59409901651160933037411349122436377001577056944370e-01L ,
/*atan_b[9]*/ 2.53815245604249931191424491383479278283630264922976e-01L,7.56455309308095037743734018000284139150046029645800e-21L ,
}
,{
/*a[10]     */ 2.73000139926648346516383602081188127403848190278175e-01L ,
/*b[10] :   */ 2.86684879348826103653358546297091891119634965434670e-01L ,
/*atan_b[10]*/ 2.79196770044925012070049716306208154037449276074767e-01L,-2.52115788641577571295756044335677296592687943925995e-21L ,
}
,{
/*a[11]     */ 3.00469565029600975134893331013376561555834254185520e-01L ,
/*b[11] :   */ 3.14359785700871038210697100412360782684118021279573e-01L ,
/*atan_b[11]*/ 3.04578294465878627494048389023895140326203545555472e-01L,2.91230434592492772694189684967968754208118542272081e-22L ,
}
,{
/*a[12]     */ 3.28361285690481774678262393368066760807466830418924e-01L ,
/*b[12] :   */ 3.42479972833279288854397420793773676450655329972506e-01L ,
/*atan_b[12]*/ 3.29959818867797216379112237860660172827920177951455e-01L,9.30919107029496230740423735124228172173872279217061e-21L ,
}
,{
/*a[13]     */ 3.56721931693259055874505029587211651856214717987120e-01L ,
/*b[13] :   */ 3.71093432391343328410242621839820742479787440970540e-01L ,
/*atan_b[13]*/ 3.55341343251416258219388746852906990625342587009072e-01L,1.05238591424673141000163053238160966240559825585058e-21L ,
}
,{
/*a[14]     */ 3.85600945252912803692499039003231191720641179521153e-01L ,
/*b[14] :   */ 4.00251150738601814323960534358626262019242858514190e-01L ,
/*atan_b[14]*/ 3.80722867617518378200239248521086210530484095215797e-01L,-1.21945811870033495672278691057491669776578154458509e-20L ,
}
,{
/*a[15]     */ 4.15050955725992341472273957165949013751986760007989e-01L ,
/*b[15] :   */ 4.30007504761513240142210140470879764507117215543985e-01L ,
/*atan_b[15]*/ 4.06104391966931330934563806889237014274840475991368e-01L,2.65998962597399045630215293174401738151071787628836e-21L ,
}
,{
/*a[16]     */ 4.45128198220858601154729507448273565784681133190970e-01L ,
/*b[16] :   */ 4.60420705138676883411271920087948217314988141879439e-01L ,
/*atan_b[16]*/ 4.31485916300525867999758264370591120950848562642932e-01L,-5.15731898573788000867228224617550054933376770292499e-21L ,
}
,{
/*a[17]     */ 4.75892983535654960900184477034957958538394330627699e-01L ,
/*b[17] :   */ 4.91553295129659681411823587970921778378396993502975e-01L ,
/*atan_b[17]*/ 4.56867440619213494398158717513247495389805408194661e-01L,-1.17767132157456183414344600410550075200279622028076e-20L ,
}
,{
/*a[18]     */ 5.07410228170177445558907530181202563476000281365126e-01L ,
/*b[18] :   */ 5.23472714391912459942074464791517129924613982439041e-01L ,
/*atan_b[18]*/ 4.82248964923944120283556130646118731419846881181002e-01L,7.19228812371825763087471157928804601190451351795533e-21L ,
}
,{
/*a[19]     */ 5.39750054761637700814449941371777322570256912129319e-01L ,
/*b[19] :   */ 5.56251939105489768655314619660856578775565139949322e-01L ,
/*atan_b[19]*/ 5.07630489215703613835577873159010664494417142122984e-01L,1.95729185540933029018896909629355663993263278227122e-20L ,
}
,{
/*a[20]     */ 5.72988475252136229153362345470036573847020634274658e-01L ,
/*b[20] :   */ 5.89970211851368934573985880476243437442462891340256e-01L ,
/*atan_b[20]*/ 5.33012013495511261082417803214283935631101485341787e-01L,1.19136600379842308834059395767709777186646606458244e-20L ,
}
,{
/*a[21]     */ 6.07208171494496323570585450136999928494042072413638e-01L ,
/*b[21] :   */ 6.24713877348479113026710057843260415211261715739965e-01L ,
/*atan_b[21]*/ 5.58393537764417140017384616479390047061315272003412e-01L,1.60618754495076238470882310232850107535836684871974e-21L ,
}
,{
/*a[22]     */ 6.42499390954343606010936791107363164108340977746831e-01L ,
/*b[22] :   */ 6.60577343433393635583391473309333719043934252113104e-01L ,
/*atan_b[22]*/ 5.83775062023499415216325897359794794283516239374876e-01L,4.35252648168202510134394817934791829596865136622329e-21L ,
}
,{
/*a[23]     */ 6.78960978813340439010418458717160717274973479682160e-01L ,
/*b[23] :   */ 6.97664190728041029999472594225196075967687647789717e-01L ,
/*atan_b[23]*/ 6.09156586273861560165872319760893560669501312077045e-01L,1.16980357484588651119506030046331492746458861536954e-20L ,
}
,{
/*a[24]     */ 7.16701572306941472702660857359560926553184289676267e-01L ,
/*b[24] :   */ 7.36088459496464051585659649212800559325842186808586e-01L ,
/*atan_b[24]*/ 6.34538110516629514322711064222559684822044800966978e-01L,1.04271379790869044477776255742912246791868144138838e-20L ,
}
,{
/*a[25]     */ 7.55840988781748681529424123295264811121247558513562e-01L ,
/*b[25] :   */ 7.75976148518263165846948342663225162141316104680300e-01L ,
/*atan_b[25]*/ 6.59919634752948782276463224327756051934557035565376e-01L,-1.49707000168437254867185968448020110086938384414132e-21L ,
}
,{
/*a[26]     */ 7.96511846049556100870729410829982316343265859222562e-01L ,
/*b[26] :   */ 8.17466968767843598319116499295589051143906544893980e-01L ,
/*atan_b[26]*/ 6.85301158983981482551370301159465725504560396075249e-01L,2.26378453363027050436135458770294067540690440344722e-20L ,
}
,{
/*a[27]     */ 8.38861462565995566516507125655143945180189448200243e-01L ,
/*b[27] :   */ 8.60716404767067592908747625246590473579999525099993e-01L ,
/*atan_b[27]*/ 7.10682683210903353798835319077298322554270271211863e-01L,-2.05816942072267395453305456292103819891300383499067e-20L ,
}
,{
/*a[28]     */ 8.83054096327761123407402015796301185982961275018315e-01L ,
/*b[28] :   */ 9.05898149317818312002345559896809845668030902743340e-01L ,
/*atan_b[28]*/ 7.36064207434900725319712466721000510005978867411613e-01L,-2.01495891478093883255259057095598284567266076155582e-20L ,
}
,{
/*a[29]     */ 9.29273595909162104414831936686333705299409223136150e-01L ,
/*b[29] :   */ 9.53206993785724477057791359513316820084583014249802e-01L ,
/*atan_b[29]*/ 7.61445731657167461023643512119107867874845396727324e-01L,1.47965126934808321509456759477582856707733884056372e-20L ,
}
,{
/*a[30]     */ 9.77726555752981243330808011822410329661495519093198e-01L ,
/*b[30] :   */ 1.00286227737052556691944860123300031773396767675877e+00L ,
/*atan_b[30]*/ 7.86827255878901883601704569937140831825672648847103e-01L,-2.49482501517232918872374648277419736886605467025447e-20L ,
}
,{
/*a[31]     */ 1.02864609206350805084140161862944784564808293337947e+00L ,
/*b[31] :   */ 1.05511202646791504811910750172287976056395564228296e+00L ,
/*atan_b[31]*/ 8.12208780101303686881249188633802305048448033630848e-01L,1.96461905827059736765985245197019056188424880993332e-20L ,
}
,{
/*a[32]     */ 1.08229638730567915046224506841117525832899403036327e+00L ,
/*b[32] :   */ 1.11023795151925827769112675724727523629553616046906e+00L ,
/*atan_b[32]*/ 8.37590304325570845578666223651964628515997901558876e-01L,4.77668553328124723447016157387373681394230124469672e-21L ,
}
,{
/*a[33]     */ 1.13897819300824750110026713455197322166401899613175e+00L ,
/*b[33] :   */ 1.16856151675095125820440233876951197089510969817638e+00L ,
/*atan_b[33]*/ 8.62971828552896528467374553938995518365118186920881e-01L,2.55195648839450962773383050246911687940245767371150e-20L ,
}
,{
/*a[34]     */ 1.19903553596581003210823783418146470970525164116258e+00L ,
/*b[34] :   */ 1.23045136228081621770132775273154379647166933864355e+00L ,
/*atan_b[34]*/ 8.88353352784466024664664085541687654767883941531181e-01L,1.41663860918952637119424194776437812752208835503398e-20L ,
}
,{
/*a[35]     */ 1.26286394722716557298308552637571192753133513841112e+00L ,
/*b[35] :   */ 1.29633244442242035832178054244323561761120799928904e+00L ,
/*atan_b[35]*/ 9.13734877021453689705226403061644191438972484320402e-01L,1.35938158484232369531731558502252718011660684187715e-20L ,
}
,{
/*a[36]     */ 1.33092063388866300837157174273995154222416258004689e+00L ,
/*b[36] :   */ 1.36669737760087601715925514911376126292452681809664e+00L ,
/*atan_b[36]*/ 9.39116401265019920129202557479430879538995213806629e-01L,2.59014288448756031532855884942098995887757875539126e-20L ,
}
,{
/*a[37]     */ 1.40373715148086175686920053249645601637145483857833e+00L ,
/*b[37] :   */ 1.44212062317890074136100819757189128722529858350754e+00L ,
/*atan_b[37]*/ 9.64497925516308163957322763248924957224517129361629e-01L,2.26449827804982598409987486349767644635807688391558e-20L ,
}
,{
/*a[38]     */ 1.48193532552453364304137000542447266699467290887996e+00L ,
/*b[38] :   */ 1.52327639603630905871124029404839461676601786166430e+00L ,
/*atan_b[38]*/ 9.89879449776441974696763320684667064597306307405233e-01L,-2.05144805536593178229841247027644547853640074453000e-20L ,
}
,{
/*a[39]     */ 1.56624743831976753224512371327739997328623336583318e+00L ,
/*b[39] :   */ 1.61096147803441905560321856238914506320725195109844e+00L ,
/*atan_b[39]*/ 1.01526097404652211662976629691357288720610085874796e+00L,1.55023677688950991064710439859627109422709756104447e-21L ,
}
,{
/*a[40]     */ 1.65754207708184680379297330985407381999685675116978e+00L ,
/*b[40] :   */ 1.70612458293084534295767223932571710065531078726053e+00L ,
/*atan_b[40]*/ 1.04064249832762372913706749866236123125418089330196e+00L,-2.04790285052346263108315613096497455796579459366338e-20L ,
}
,{
/*a[41]     */ 1.75685758736121220779123774339350281513663381064643e+00L ,
/*b[41] :   */ 1.80990457885083358467812747472081014166178647428751e+00L ,
/*atan_b[41]*/ 1.06602402262079355645292555454517469115671701729298e+00L,1.35761391457454697238630079551792662430377488900508e-20L ,
}
,{
/*a[42]     */ 1.86544587781964999316146180453643112839113228663557e+00L ,
/*b[42] :   */ 1.92368085119253588136274679687431898855720646679401e+00L ,
/*atan_b[42]*/ 1.09140554692704725130852905223832749470602720975876e+00L,-4.99912973600412204300099687136900356413053111793263e-20L ,
}
,{
/*a[43]     */ 1.98483051718814108510073200565874404907343358553592e+00L ,
/*b[43] :   */ 2.04914055707593576686337266679061031027231365442276e+00L ,
/*atan_b[43]*/ 1.11678707124736675761374204984832658738014288246632e+00L,3.10946302324418261534220010195063618443711756432142e-20L ,
}
,{
/*a[44]     */ 2.11688487740991047405177746304945089925532521933200e+00L ,
/*b[44] :   */ 2.18836977316091156413845053574362964354804717004299e+00L ,
/*atan_b[44]*/ 1.14216859558269778155553675347277930995915085077286e+00L,1.40640078849491175132740694767582500364133325443408e-20L ,
}
,{
/*a[45]     */ 2.26393888595348033211664828855751235332413889868857e+00L ,
/*b[45] :   */ 2.34397906437763570955574998766479666301165707409382e+00L ,
/*atan_b[45]*/ 1.16755011993394735431150976978642574977129697799683e+00L,-3.65632431589086661411806107644207364740664894984231e-20L ,
}
,{
/*a[46]     */ 2.42892740222016721343601364411619003865374618991270e+00L ,
/*b[46] :   */ 2.51927965826279850135825666423983193453750573098660e+00L ,
/*atan_b[46]*/ 1.19293164430198149548578018253053301123145502060652e+00L,4.73277414284342449192776814622229467942243084497994e-20L ,
}
,{
/*a[47]     */ 2.61560046981161355013387674598293220046878570571436e+00L ,
/*b[47] :   */ 2.71853573297491153746945069524798554994049482047558e+00L ,
/*atan_b[47]*/ 1.21831316868762298247143988083607268890773411840200e+00L,-3.32698220688116567699867573421587503115973351391857e-20L ,
}
,{
/*a[48]     */ 2.82882779840766997424337148646633655837718719950330e+00L ,
/*b[48] :   */ 2.94733416149008806183065556361100334470393136143684e+00L ,
/*atan_b[48]*/ 1.24369469309164922975110417757704794894380029290915e+00L,-1.68084377873484618069695715707321800300036208288904e-20L ,
}
,{
/*a[49]     */ 3.07505072362971709895160078641983571814943843203348e+00L ,
/*b[49] :   */ 3.21314087722892193746578037849559450478409416973591e+00L ,
/*atan_b[49]*/ 1.26907621751479028680918009763800569089653436094522e+00L,4.38792946241904218827598608948466154796821458517843e-20L ,
}
,{
/*a[50]     */ 3.36297230191158847569456390937866319039822318494439e+00L ,
/*b[50] :   */ 3.52616384863255472514528832128632984677096828818321e+00L ,
/*atan_b[50]*/ 1.29445774195772695714951733281239398820616770535707e+00L,-3.76594892854190752512165708240508698224814967846662e-20L ,
}
,{
/*a[51]     */ 3.70464601821196277634078130355925061867935789919545e+00L ,
/*b[51] :   */ 3.90073973345466671345041498319972106401110067963600e+00L ,
/*atan_b[51]*/ 1.31983926642108904373103250851073653393541462719440e+00L,-1.42201047639732182814773447172854731688387282967153e-20L ,
}
,{
/*a[52]     */ 4.11726034471856742723635875546283846965135299824434e+00L ,
/*b[52] :   */ 4.35765668014057021934989921696512737980810925364494e+00L ,
/*atan_b[52]*/ 1.34522079090545372721809957994310025242157280445099e+00L,-3.03025789161007606745201605098058359973216476112863e-20L ,
}
,{
/*a[53]     */ 4.62619989820138064559978332787477354097622698462263e+00L ,
/*b[53] :   */ 4.92824409985377215716664811573366478114621713757515e+00L ,
/*atan_b[53]*/ 1.37060231541134407834674896475846139765053521841764e+00L,-7.07054719690683194328303436662645365432934240975534e-21L ,
}
,{
/*a[54]     */ 5.27059285056349863215309743877271992636756004729045e+00L ,
/*b[54] :   */ 5.66202526987798314059285864630055584711953997612000e+00L ,
/*atan_b[54]*/ 1.39598383993922771069504801255689585559593979269266e+00L,-9.10562671648253215988230309564473943324088366141305e-21L ,
}
,{
/*a[55]     */ 6.11406930017863912016759088682326676363852737284111e+00L ,
/*b[55] :   */ 6.64216890962962991200313478401540123741142451763153e+00L ,
/*atan_b[55]*/ 1.42136536448951557570080650449995118833612650632858e+00L,7.52628100149995238564921704233583060300504688449482e-21L ,
}
,{
/*a[56]     */ 7.26750136287798744557578279291351829750470434026984e+00L ,
/*b[56] :   */ 8.01990986231012476740526162544142607657704502344131e+00L ,
/*atan_b[56]*/ 1.44674688906256090415499565571266771257796790450811e+00L,-4.76166414128333839459064144083355125451074263289874e-20L ,
}
,{
/*a[57]     */ 8.94284159107797415028212824375737065074638836862153e+00L ,
/*b[57] :   */ 1.01020964280654031866926723104427310317987576127052e+01L ,
/*atan_b[57]*/ 1.47212841365865829579718387920550526359875220805407e+00L,-2.94511141270828048641690533512857277905398719218800e-20L ,
}
,{
/*a[58]     */ 1.16023240149353616510359287691089007792909044742814e+01L ,
/*b[58] :   */ 1.36206610885393049918332120107322680269135162234306e+01L ,
/*atan_b[58]*/ 1.49750993827804296080769691501544116363220382481813e+00L,-4.91079244887503652449167717983894414693145750621499e-20L ,
}
,{
/*a[59]     */ 1.64826377753716879452100734158101774215127233018738e+01L ,
/*b[59] :   */ 2.08587363260064998487369747337538683495949953794479e+01L ,
/*atan_b[59]*/ 1.52289146292089011330492254181478983809938654303551e+00L,5.06637296145401718980478181281990081396813033880353e-20L ,
}
,{
/*a[60]     */ 2.83859754493342037894536299710691579018801830357118e+01L ,
/*b[60] :   */ 4.43908820444563916793323521403635822935029864311218e+01L ,
/*atan_b[60]*/ 1.54827298758731452064246747468700959871057420969009e+00L,-6.87408573264970738043205172896303636687514563517111e-21L ,
}
,{
/*a[61]     */ 1.01699461607317799313064417304063275580797148199765e+02L ,
/*b[61] :   */ 8.27932424540746422086945344176456273999065160751343e+01L ,
/*atan_b[61]*/ 1.55871863366040360279231313800352154430584050714970e+00L,4.59787536942001704904414526825329883423547987397342e-20L ,
}
,
};
/*File generated by atan_exp.mpl*/
 static const long double coef_poly[9][2] = {
{ -3.33333333333333333342368351437379203616728773340583e-01L,  9.03501810404587028364033466367082415937499719525463e-21L},
{ 2.00000000000000000002710505431213761085018632002175e-01L,  -2.71050543121376108505536620063805076318847614178820e-21L},
{ -1.42857142857142857140921067549133027796415262855589e-01L,  -1.93607530800982934641564128836546985281459293443700e-21L},
{ 1.11111111111111111109605274760436799397211871109903e-01L,  1.50583635067431171387883211317314321885579450456211e-21L},
{ -9.09090909090909090933731867556488737136533018201590e-02L, 0},
{ 7.69230769230769230779655790120052927250071661546826e-02L, 0},
{ -6.66666666666666666698289230030827212658550706692040e-02L, 0},
{ 5.88235294117647058825522430464127765503690170589834e-02L, 0},
{ -5.26315789473684210515616425929419364138084347359836e-02L, 0},
}; 
