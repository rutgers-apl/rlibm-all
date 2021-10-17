unsigned bitsSame = 7;
unsigned N = 5
double coeffs[32][4] = {
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4427706281057905979281485997489653527736663818359375000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426949620246884986585200749686919152736663818359375000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426948825518302044201846001669764518737792968750000000000000000000000000000000000000000000000000000e+00,
		-1.6666667101283866303518266249739099293947219848632812500000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426949364798418162791904251207597553730010986328125000000000000000000000000000000000000000000000000e+00,
		-5.7142857275903224945068359375000000000000000000000000000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426949485899924763288026952068321406841278076171875000000000000000000000000000000000000000000000000e+00,
		-6.6031746140548153167770806248881854116916656494140625000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950188196905333626318679307587444782257080078125000000000000000000000000000000000000000000000000e+00,
		-7.1380471505902021167599968975991941988468170166015625000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950268799474397241056067286990582942962646484375000000000000000000000000000000000000000000000000e+00,
		-7.1923278130961165732770723479916341602802276611328125000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950195379442121179636160377413034439086914062500000000000000000000000000000000000000000000000000e+00,
		-7.1929824577025169851651753560872748494148254394531250000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950376965264055684201593976467847824096679687500000000000000000000000000000000000000000000000000e+00,
		-7.2121254874980889049140841962071135640144348144531250000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950398712121703681532380869612097740173339843750000000000000000000000000000000000000000000000000e+00,
		-7.2130087487321481454216609563445672392845153808593750000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950462772494265806244584382511675357818603515625000000000000000000000000000000000000000000000000e+00,
		-7.2146143291178066458968487495440058410167694091796875000000000000000000000000000000000000000000000000e-01,
		1.0608803298562068384569556656060740351676940917968750000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950435839420716632730545825324952602386474609375000000000000000000000000000000000000000000000000e+00,
		-7.2137560854522098097163507190998643636703491210937500000000000000000000000000000000000000000000000000e-01,
		5.5188240947237732214603056490886956453323364257812500000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950418994615166212724943761713802814483642578125000000000000000000000000000000000000000000000000e+00,
		-7.2135349730091657960429074591957032680511474609375000000000000000000000000000000000000000000000000000e-01,
		4.8928531891515925078550708349212072789669036865234375000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950411825141262767147054546512663364410400390625000000000000000000000000000000000000000000000000e+00,
		-7.2134818548799317650122020495473407208919525146484375000000000000000000000000000000000000000000000000e-01,
		4.8097526657426137308704028328065760433673858642578125000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.4426950397613038656885464661172591149806976318359375000000000000000000000000000000000000000000000000e+00,
		-7.2134525776213287429072806844487786293029785156250000000000000000000000000000000000000000000000000000e-01,
		4.7941346469976509059307545612682588398456573486328125000000000000000000000000000000000000000000000000e-01,
		-4.1135332779965533278598854849406052380800247192382812500000000000000000000000000000000000000000000000e-02
	},
	{
		1.4426950407585850122416104568401351571083068847656250000000000000000000000000000000000000000000000000e+00,
		-7.2134737790965031134504670262685976922512054443359375000000000000000000000000000000000000000000000000e-01,
		4.8084492572074633010004163224948570132255554199218750000000000000000000000000000000000000000000000000e-01,
		-3.5300623169669498313538724687532521784305572509765625000000000000000000000000000000000000000000000000e-01
	},
	{
		1.4426950404954139717261796249658800661563873291015625000000000000000000000000000000000000000000000000e+00,
		-7.2134725011798661586936987077933736145496368408203125000000000000000000000000000000000000000000000000e-01,
		4.8083087641098110065485116138006560504436492919921875000000000000000000000000000000000000000000000000e-01,
		-3.5339430743329897088855773290561046451330184936523437500000000000000000000000000000000000000000000000e-01
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	}
};


