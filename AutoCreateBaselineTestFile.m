% Create the test file, test suite, and test case structure
tf = sltest.testmanager.TestFile('QualificationTest');
ts = createTestSuite(tf,'AcquireDriveAction');
tc = createTestCase(ts,'baseline','RHP-123456');


% Get the test file options
opt = getOptions(tf);

% Set the title for the report and specify to save figures
opt.Title = 'ABC Co. Test Results';
opt.Author = 'andre'
opt.SaveFigures = false;

tcOpt = getOption(tc)


% Remove the default test suite
tsDel = getTestSuiteByName(tf,'New Test Suite 1');
remove(tsDel);

% Assign the system under test to the test case
setProperty(tc,'Model','sldemo_absbrake');


% Capture the baseline criteria
baseline = captureBaselineCriteria(tc,'baseline_API.mat',true);

% Test a new model parameter by overriding it in the test case
% parameter set
ps = addParameterSet(tc,'Name','API Parameter Set');
po = addParameterOverride(ps,'m',55);

% Set the baseline criteria tolerance for one signal
sc = getSignalCriteria(baseline);
sc(1).AbsTol = 9;

% Run the test case and return an object with results data
ResultsObj = run(tc);

% Open the Test Manager so you can view the simulation
% output and comparison data
sltest.testmanager.view;

% Generate a report from the results data
filePath = 'test_report.pdf';
sltest.testmanager.report(ResultsObj,filePath,...
          'Author','Test Engineer',...
          'IncludeSimulationSignalPlots',true,...
          'IncludeComparisonSignalPlots',true);