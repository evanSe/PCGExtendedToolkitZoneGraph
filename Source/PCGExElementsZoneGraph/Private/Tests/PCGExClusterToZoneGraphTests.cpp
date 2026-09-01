// Copyright 2026 Timothée Lapetite and contributors
// Released under the MIT license https://opensource.org/license/MIT/

#include "Graph/PCGExClusterToZoneGraph.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphReversedRoadRadiusAssignmentTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.ReversedRoadRadiusAssignment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphReversedRoadRadiusAssignmentTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TestTrue(TEXT("Matching node identity maps to the materialized road start"), IsPrecomputedRoadStart(10, 10));
	TestFalse(TEXT("Opposite single-edge storage direction maps the seed junction to the road end"), IsPrecomputedRoadStart(10, 20));
	TestTrue(TEXT("Reversed materialization maps the other junction to the road start"), IsPrecomputedRoadStart(20, 20));
	TestFalse(TEXT("The other junction never claims the materialized start"), IsPrecomputedRoadStart(20, 10));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphClosedLoopTerminalAppendTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.ClosedLoopTerminalAppend",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphClosedLoopTerminalAppendTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TArray<int32> Nodes;
	Nodes.Reserve(6);
	Nodes.Append({ 2, 4, 6, 8, 10, 12 });
	TestEqual(TEXT("Fixture fills its allocation before the append"), Nodes.Num(), Nodes.Max());

	AppendClosedLoopTerminal(Nodes);

	TestEqual(TEXT("Closed loop receives one terminal node"), Nodes.Num(), 7);
	TestEqual(TEXT("Terminal node repeats the previous last node"), Nodes.Last(), 12);
	return true;
}

#endif
