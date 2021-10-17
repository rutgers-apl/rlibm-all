unsigned bitsSame = 6;
unsigned N = 6
double coeffs[64][3] = {
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000174868446389808696039835922420024871826171875000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000020587618276834973585209809243679046630859375000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000037404157549048022701754234731197357177734375000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000005120481816334176983218640089035034179687500000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000834106117508781608194112777709960937500000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000001164970342415472259745001792907714843750000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000050197623835401827818714082241058349609375000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000119868559522728901356458663940429687500000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000053987925241472112247720360755920410156250000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000024664714715072477702051401138305664062500000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000000313082892944294144399464130401611328125000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999902400293905202488531358540058135986328125000000000000000000000000000000000000000000000000e-01,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999618993662409138778457418084144592285156250000000000000000000000000000000000000000000000000e-01,
		-2.8590153121488088849844189098803326487541198730468750000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999953348428505250922171398997306823730468750000000000000000000000000000000000000000000000000e-01,
		-4.8860526315789467588501793215982615947723388671875000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999734057176681290002306923270225524902343750000000000000000000000000000000000000000000000000e-01,
		-4.8523469136182795224954134027939289808273315429687500000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999951982854184961979626677930355072021484375000000000000000000000000000000000000000000000000e-01,
		-4.9301689332766676088226631691213697195053100585937500000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999965616392927358901943080127239227294921875000000000000000000000000000000000000000000000000e-01,
		-4.9342524435096644097598073130939155817031860351562500000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999990907273428319967933930456638336181640625000000000000000000000000000000000000000000000000e-01,
		-4.9347564505568310977423607255332171916961669921875000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999999000799277837359113618731498718261718750000000000000000000000000000000000000000000000000e-01,
		-4.9348009291254033570339743164367973804473876953125000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		9.9999999999999267252803747396683320403099060058593750000000000000000000000000000000000000000000000000e-01,
		-4.9348017514297941588097273779567331075668334960937500000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000000059952043329758453182876110076904296875000000000000000000000000000000000000000000000000e+00,
		-4.9348023167641192898713597969617694616317749023437500000000000000000000000000000000000000000000000000e+00,
		4.6294435836718976773340727959293872117996215820312500000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000000217603712826530681923031806945800781250000000000000000000000000000000000000000000000000e+00,
		-4.9348022848475556756397963908966630697250366210937500000000000000000000000000000000000000000000000000e+00,
		4.1296697841083300772879738360643386840820312500000000000000000000000000000000000000000000000000000000e+00
	},
	{
		1.0000000000000048849813083506887778639793395996093750000000000000000000000000000000000000000000000000e+00,
		-4.9348022056942788537980959517881274223327636718750000000000000000000000000000000000000000000000000000e+00,
		4.0600136972547158364932329277507960796356201171875000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	},
	{
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00,
		0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+00
	}
};

